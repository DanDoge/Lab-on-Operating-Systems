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
 - [x] 完善fakeContainer.c, 添加cgroup子系统, 资源上限1核心, 512MB. 自选压力测试程序. 讨论内存占用超出时, 是否会kill掉
    - [x] 完善fakeContainer.c
    - [x] 自选压力测试
    - [x] 讨论内存超出
 - [x] lab1的代码方面的提高

## Lab3

 - [x]叙述linux网络包处理流程
 - [x]使用iptables实现以下功能
     - [x]拒绝某一ip的访问
     - [x]只开放本机的http和ssh服务, 拒绝所有其他协议和端口
     - [x]拒绝回应某一个ip的ping
 - [x]解释路由和交换的区别, 介绍bridge veth的工作原理
 - [x]改进fakeContainer
    - [x]能够访问internet
    - [x]部署能够访问的nginx服务器
    - [x]解释外部访问web服务的过程中, 网络包在服务器上经过了什么
 - [x]修补, 最终确认一下, 咕咕咕

## Lab4

 - [x] 叙述以下的容器通信的处理
    - [x] 同一子网的两容器
    - [x] 不同子网的两容器
    - [x] gre隧道相连的两host上的两容器
 - [x] 叙述vlan原理, 解释用户隔离数量的差别
 - [x] 调研vxlan技术, 比较和gre的差别
 - [x] 基于vlan和gre构建两个隔离的容器集群, 体现隔离性和相通性
 - [x] 基于ovs限制流量, 测评

## Lab5

 - [ ] 模拟Raft协议工作场景, 叙述处理过程
 - [ ] 调研GlusterFS和AUFS文件系统, 说明工作原理特点和使用方式
 - [ ] 安装配置GlusterFS, 启动容错机制, 挂载到lxc容器中
 - [ ] 使用联合文件系统为lxc提供镜像服务, 节约空间, 详细阐述过程

###### last modified date: 2018-04-30
