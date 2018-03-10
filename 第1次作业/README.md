# 第一次作业

## 总结, 叙述, 对比虚拟机和容器

### 虚拟机

在原有的计算机硬件(也可以是在宿主操作系统)基础之上, 通过增加一层虚拟机管理层,
运行客户操作系统, 将内存I/O等虚拟化, 产生出客户操作系统直接运行在硬件上面的假象,
这样可以在同一套硬件上运行多个操作系统

### 容器

在宿主操作系统之上增加容器层, 并不需要对每一个容器安排一个单独的操作系统,
同一个机器上的多个容器共享一个内核, 似乎可以将容器看做在应用层上的虚拟化

### 对比

| 属性 | 虚拟机 | 容器 |
| - | :-: | -: |
| 大小 | 通常较大 | 通常小 |
| 速度 | 比较慢 | 比较快 |
| 隔离程度 | 深(系统层级) | 浅(应用级) |
| 资源利用率 | 通常比较低 | 通常比较高 |

###### 参考资料

[容器和虚拟机的区别](http://blog.csdn.net/xiangxianghehe/article/details/70568448)

[docker容器与虚拟机有什么区别？](https://www.zhihu.com/question/48174633)

[虚拟机和容器的对比 Virtual Server VS Docker](http://www.cnblogs.com/frankyou/p/6427636.html)

[如何看待docker容器与虚拟机之间的比较](http://blog.csdn.net/albenxie/article/details/73478897)

## 试用 lxc-python-api

最终的文件在[这里](https://github.com/DanDoge/Lab-on-Operating-Systems/blob/master/%E7%AC%AC1%E6%AC%A1%E4%BD%9C%E4%B8%9A/lab1.py)

遇到的问题: 在Ubuntu机器上不能创建debian容器(not fixed, until 03/10)

###### 参考资料

[python-api](https://stgraber.org/2014/02/05/lxc-1-0-scripting-with-the-api/)

## 比较 docker 和 lxc

not finished

###### last modified date: 03/10
