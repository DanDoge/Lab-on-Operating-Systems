### 进度

05-20 输入任务, [测试界面](http://47.93.217.74/oslab.html), [结果](http://47.93.217.74/out.txt)

### 测试

05-20

输入

![](./pic/test0520_1.jpg)

php输出

![](./pic/test0520_2.jpg)

cpp输出

![](./pic/test0520_3.jpg)

05-25

镜像脚本不work了....惊了 ==> 因为我是智障...在Linux里用\\r...把/var/lib/lxc删了...

php提权? ==> 用sudo就行...

进程状态怎么办?

05-25

aufs用不了了....暂时不能随时创建镜像...

glusterfs & 输出重定向做完了...?

进程状态怎么办?

(这就不是master-slave架构的吧...但是不会http只能这样...或者把容器扔到gre对端...假装是slave)

![](./pic/test0527_1.jpg)

![](./pic/test0527_2.jpg)

![](./pic/test0527_3.jpg)

![](./pic/test0527_4.jpg)

### 已知bug

 - 命令行有空格请务必用双引号包裹
 - 任务名不要中文编码(主要是txt那里的问题)
 - 一用aufs就死机...lxc不能用...就要回档...
 - 回档之后apache要重启
