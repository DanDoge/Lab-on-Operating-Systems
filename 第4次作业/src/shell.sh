# 只是模拟实验的过程, 网关的设置类似课件中的方法

# host1
ip netns add red
ip link add vethr type veth peer name veth_r
ip link set vethr netns red
ip netns exec red ip addr add 172.16.1.10/24 dev vethr
ip netns add blue
ip link add vethb type veth peer name veth_b
ip link set vethb netns blue
ip netns exec blue ip addr add 172.16.1.20/24 dev vethb

ovs-vsctl add-br br1
ovs-vsctl add-port br1 veth_r
ip link set veth_r up
ovs-vsctl set port veth_r tag=10
ovs-vsctl add-port br1 veth_b
ip link set veth_b up
ovs-vsctl set port veth_b tag=20

ovs-vsctl add-port br1 gre0 -- set interface gre0 type=gre options:remote_ip=$host2

# host2
sudo ip netns add green
sudo ip link add vethg type veth peer name veth_g
sudo ip link set vethg netns green
sudo ip netns exec green ip addr add 172.16.1.21/24 dev vethg

sudo ovs-vsctl add-br br2
sudo ovs-vsctl add-port br2 veth_g
sudo ip link set veth_g up
sudo ovs-vsctl set port veth_g tag=20

sudo ovs-vsctl add-port br2 gre0 -- set interface gre0 type=gre options:remote_ip=$host1
