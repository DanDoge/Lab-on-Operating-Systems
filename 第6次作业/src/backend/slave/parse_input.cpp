#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "rpc/server.h"

using namespace std;

int run(char* jobname, char* cmd_line, int max_retry_time, int time_out, char* image_id, char* cpu_limit, char* mem_limit) {
    char cmd[1024] = {};

    // set up working dir for this job
    sprintf(cmd, "mkdir -p /var/www/shareddata/%s", jobname);
    system(cmd);

    // set up out file, config file, status file
    sprintf(cmd, "touch /var/www/shareddata/%s/out.txt", jobname);
    system(cmd);

    sprintf(cmd, "touch /var/www/shareddata/%s/config.txt", jobname);
    system(cmd);

    sprintf(cmd, "touch /var/www/shareddata/%s/status.txt", jobname);
    system(cmd);

    sprintf(cmd, "/var/www/shareddata/%s/config.txt", jobname);
    ofstream out2(cmd);
    out2 << image_id << endl;
    out2.close();

    sprintf(cmd, "/var/www/shareddata/%s/status.txt", jobname);
    ofstream out3(cmd);
    out3 << -1 << endl; // -1 -> 初始化失败, 0 -> 运行成功, 1 - 255 -> 运行失败
    out3.close();

    sprintf(cmd, "sudo lxc-start -n %s", image_id);
    system(cmd);

    sprintf(cmd, "lxc-cgroup -n %s cpuset.cpus \"%s\"", image_id, cpu_limit);
    system(cmd);

    sprintf(cmd, "lxc-cgroup -n %s memory.limit_in_bytes \"%s\"", image_id, mem_limit);
    system(cmd);

    int now_try_time = 0;
    while(now_try_time++ < max_retry_time){
        sprintf(cmd, "lxc-attach -n %s -- %s > /var/www/shareddata/%s/out.txt && sudo echo 0 > /var/www/shareddata/%s/status.txt", image_id, cmd_line, jobname, jobname);
        system(cmd);

        sleep(time_out);

        sprintf(cmd, "/var/www/shareddata/%s/status.txt", jobname);
        ifstream in1(cmd);
        int status = 1;
        in1 >> status;
        in1.close();
        if(status == 0){
            break;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {

    rpc::server srv(8080);

    srv.bind("run", &run);

    //srv.bind("query", &query);

    // Run the server loop.
    srv.run();

    return 0;
}
