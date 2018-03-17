# Lab on Operating Systems

黄道吉 1600017857

## Lab1

- [x] 了解虚拟机和容器技术，用自己的话简单叙述、总结并对比；
- [x] 在ubuntu系统（版本14.04及其以上）中，安装配置LXC，使用lxc命令行工具对容器生命周期进行管理：分别尝试创建、启动、停止、删除容器，无需写在报告里；
- [x] 了解namespace、Cgroup、rootfs等机制，无需写在报告里；
    - [x] namespaces
    - [x] Cgroup
    - [x] rootfs
- [x] 利用LXC Python API编写程序，要求执行该程序会先创建并启动一个Debain系统容器，然后该程序会在容器根目录创建一个名为 Hello-Container的文件，并在文件中写入姓名和学号，最后该程序会停止当前容器。程序需和报告一起提交。
- [x] 对docker和lxc进行比较。

## Lab2

 - [x] 阅读rootfs制作脚本, 说明制作流程
    - [x] 阅读debian制作脚本
    - [x] 说明制作流程
 - [ ] 完善fakeContainer.c, 添加cgroup子系统, 资源上限1核心, 512MB. 自选压力测试程序. 讨论内存占用超出时, 是否会kill掉
    - [x] 完善fakeContainer.c
    - [x] 自选压力测试
    - [ ] 讨论内存超出
 - [x] lab1的代码方面的提高

###### last modified date: 2018-03-17
