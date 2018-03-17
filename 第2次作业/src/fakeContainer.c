#define _GNU_SOURCE

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <time.h>
#include <signal.h>
#include <libcgroup.h>

#define STACK_SIZE (1024 * 1024)
#define MEMORY_LIMIT (512*1024*1024)

//rootfs在本机所在路径
//TODO:rootfs的路径需要根据自己的配置来设置
const char* rootfs = "/var/lib/lxc/ubuntu-test/rootfs";

//container 主机名
const char* hostname = "fakeContainer";

static char child_stack[STACK_SIZE];
char* const child_args[] = {
    "/bin/bash",
    NULL
};

//父子进程同步
int pipe_fd [2];

int child_main(void* args) {
    char c;
    printf("In child process(container)\n");
    //用chroot 切换根目录
    chroot(rootfs);
    if(errno != 0){
        perror("chroot()");
        exit(1);
    }

    //clone 调用中的 CLONE_NEWUTS起隔离主机名和域名的作用
    sethostname(hostname, sizeof(hostname));
    if( errno != 0 ){
        perror("sethostname()!");
        exit(1);
    }
    //挂载proc子系统，CLONE_NEWNS 起隔离文件系统作用
    mount("proc", "/proc", "proc", 0, NULL);
    if (errno != 0){
        perror("Mount(proc)");
        exit(1);
    }

    //切换的根目录
    chdir("/");

    close(pipe_fd[1]);
    read(pipe_fd[0], &c, 1);

    //将子进程的镜像替换成bash
    execv(child_args[0], child_args);
    return 1;

}

struct cgroup*  cgroup_control(pid_t pid){
    struct cgroup *cgroup = NULL;
    int ret;
    ret = cgroup_init();
    char* cgname = malloc(30*sizeof(char));
    if (ret) {
        printf("error occurs while init cgroup.\n");
        return NULL;
    }

    time_t now_time = time(NULL);
    sprintf(cgname, "fakecontainer_%d", (int)now_time);
    printf("%s\n", cgname);

    cgroup = cgroup_new_cgroup(cgname);
    if( !cgroup ){
        ret = ECGFAIL;
        printf("Error new cgroup%s\n", cgroup_strerror(ret));
        goto out;
    }

    //添加cgroup cpuset子系统
    struct cgroup_controller *cgc_cpuset = cgroup_add_controller(cgroup, "cpuset");
    if (  !cgc_cpuset ){
        ret = ECGINVAL;
        printf("Error add controller %s\n", cgroup_strerror(ret));
        goto out;
    }

    //限制只能使用0和1号cpu
    if (  cgroup_add_value_string(cgc_cpuset, "cpuset.cpus", "0-1") ){
        printf("Error limit cpuset cpus.\n");
        goto out;
    }

    // TODO:添加cgroup memory子系统，设置内存上限为512MB
    /*  Time:      03/14  11:19
     *  reference: https://www.kernel.org/doc/Documentation/cgroup-v1/memory.txt
     *             http://libcg.sourceforge.net/html/index.html
     *  not tested, and i havn't read document...
     */
    struct cgroup_controller *cgc_memory = cgroup_add_controller(cgroup, "memory");
    if(  !cgc_memory ){
        /* what's ECGINVAL? */
        ret = ECGINVAL;
        printf("Error add controller %s\n", cgroup_strerror(ret));
        goto out;
    }
    /* should i choose this function? */
    if(  cgroup_add_value_int64(cgc_memory, "memory.limit_in_bytes", MEMORY_LIMIT)){
        printf("Error limit memory.\n");
        goto out;
    }

    ret = cgroup_create_cgroup(cgroup, 0);
    if (ret){
        printf("Error create cgroup%s\n", cgroup_strerror(ret));
        goto out;
    }
    ret = cgroup_attach_task_pid(cgroup, pid);
    if (ret){
        printf("Error attach_task_pid %s\n", cgroup_strerror(ret));
        goto out;
    }

    return cgroup;
out:
    if (cgroup){
        cgroup_delete_cgroup(cgroup, 0);
        cgroup_free(&cgroup);
    }
    return NULL;

}

int main() {
    char* cmd;
    printf("main process: \n");

    pipe(pipe_fd);

    if( errno != 0){
        perror("pipe()");
        exit(1);
    }

    int child_pid = clone(child_main, child_stack + STACK_SIZE, CLONE_NEWNET | CLONE_NEWNS | CLONE_NEWPID | CLONE_NEWIPC | CLONE_NEWUTS | SIGCHLD, NULL);

    struct cgroup* cg = cgroup_control(child_pid);

    close(pipe_fd[1]);

    waitpid(child_pid, NULL, 0);
    if (cg) {
        cgroup_delete_cgroup(cg, 0); //删除cgroup 子系统
    }
    printf("child process exited.\n");
    return 0;
}
