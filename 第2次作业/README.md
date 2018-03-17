# 第二次作业

## 说明任意linux发行版的roofs制作流程

阅读的是lxc-Debian

#### install_debian

首先检查缓存文件夹中是否有这个发行版, 如果没有, 就下载一个新的.

将下载/缓存好的发行版文件复制到目标文件夹.

#### configure_debian

首先检测各个设备是否存在, 没有就创建设备文件.

配置/etc/inittab

将/proc/self/mtab映射到rootfs/etc/mtab

配置网络接口, hostname

配置系统语言

生成新的ssh key(**没看懂**)

设置时区

#### copy_configuration

确保有一个hwaddr, 把容器的配置信息写到rootfs外的配置文件里面(**需要确认**)

#### configure_debian_systemd

配置systemd, 主要在处理各个设备的配置

#### post_process

检查架构, 如果和宿主不一样, 安装一个新的架构

把架构之类的信息写到rootfs/etc/apt/里面.

在容器内安装一些包

#### 善后工作

有必要的话, 清掉cache中的文件

## 完善代码, 压力测试, 讨论

#### 代码

我觉得是对的...至少结果确实限制住内存了

#### 压力测试

四张图片

内存是被限制住的, 在这次测试中进程也没有被杀死, 乖乖去读文档吧

#### 讨论

cgroup文档中描述的是, 如果内存使用超过设定的限制, 会先执行回收程序(LRU)尝试回收内存, 如果失败的话, 则占用内存最高的程序会被杀死

用stress中内存压力测试是不断分配内存写'z', (至少这次实验)没有出现程序被杀死的情况

```c
int
hogvm (long long bytes, long long stride, long long hang, int keep)
{
    long long i;
    char* ptr = 0;
    char c;
    int do_malloc = 1;

    while (1)
    {
        if (do_malloc)
        {
            dbg (stdout, "allocating %lli bytes ...\n", bytes);
            if (!(ptr = (char *) malloc (bytes * sizeof (char))))
            {
                err (stderr, "hogvm malloc failed: %s\n", strerror (errno));
                return 1;
            }
            if (keep)
            do_malloc = 0;
        }



        for (i = 0; i < bytes; i += stride)
        {
            c = ptr[i];
            if (c != 'Z')
            {
                err (stderr, "memory corruption at: %p\n", ptr + i);
                return 1;
            }
        }
    return 0;
}
```

文档中描述了当内存限制很小的时候,  会出现程序被杀死的情况, 但是还没有复现 (**需要实验**)

## lab1代码的完善

#### 健壮性

lab1的初始代码中没有考虑很多可能失败的地方(比方说创建/启动/调用容器失败),而这些地方在lab1的代码中都没有考虑, 至少也可以输出错误信息.

#### 访问容器

lxc访问容器可以通过lxc-attach, lxc-console来访问容器

但是lab1中只涉及把硬编码的函数调给容器, 既不能访问容器的shell, 也没有涉及传递个性化的参数和函数, 这是可以加以改进的地方.

#### 资源隔离

lab1的代码并没有设置资源的限制, 理论上容器运行的程序可以耗尽宿主机的内存

所以可能需要添加代码来限制容器能使用的内存, cpu数量和网络等其他的资源.

###### last modified date: 03/17
