# 主机内

# pid为容器的pid, main里面可以获取
ln -s /proc/$pid/ns/net /var/run/netns/$pid

brtcl addbr bridge_0

ifconfig bridge_0 $bridge netmask 255.255.255.0 up

ip link add vethB type veth peer vethC

brctl addif bridge_0 vethB

ifconfig vethB up

ip link set vethC netns $pid_t

ip netns exec $pid ip link set dev vethC name eth0

ip netns $pid exec ifconfig vethC $container netmask 255.255.255.0 up

# 至此, 网络结构应该是建立完毕了
# 主机在这里能ping通容器

# 访问网络

# 这一句可能是没有用的, 但是至少能ping通主机, 但是不能上外网
# 似乎这句只让所有包从eth0发出去, 网桥自然可以看到, 主机也能看到

ip netns $pid exec ip route add default dev eth0

iptables -t nat -A POSTROUTING -s $container -j SNAT --to $host

# 可以上网了, 所有包的下一跳是主机(连接了外网)
# (host是内网地址还是公网地址来着...好像用内网地址也行...吗?)

ip netns $pid exec route add default gw $host dev eth0

# 端口映射, 假设这里宿主机打开了转发

iptables -t nat -A PREROUTING -p tcp --dport $port -j DNAT --to-destination $container:80

iptables -t nat -A POSTROUTING -d $container -p tcp --dport 80 -j --to $host
