import lxc
import sys

# 如果没有创建过debian的容器, 可以用下面的代码调用命令行创建一个
#
# import os
#
# os.system("lxc-create -n debian-test -t debian")
#

# 这里假定创建过名为debian-test的容器
c = lxc.Container("debian-test")

# 也可以在这里用 c.create() 的方式创建容器
# 但是本地测试均失败了(linux kernel 4.4.0-85, ubuntu 16.04)

if not c.running:
    c.start()

# 写文件的函数
def write_file():
    with open("/Hello-Container", "w") as fd:
        fd.write("HuangDaoji 1600017857")

# 在容器中调用
c.attach_wait(write_file)

# 善后工作
if not c.shutdown(30):
    print("Failed to cleanly shutdown the container, forcing.")
    if not c.stop():
        print("Failed to kill the container", file=sys.stderr)
        sys.exit(1)
