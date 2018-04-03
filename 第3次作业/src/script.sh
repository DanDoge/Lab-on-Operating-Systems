# 主机内

# pid为容器的pid
ln -s /proc/$pid/ns/net /var/run/netns/$pid

brtcl addbr bridge_0

ifconfig bridge_0 $bridge netmask 255.255.255.0 up

ip link add vethB type veth peer vethC

brctl addif bridge_0 vethB

ifconfig vethB up

ip link set vethC netns $pid_t

ip netns $pid exec ifconfig vethC $container netmask 255.255.255.0

# 至此, 网络结构应该是建立完毕了

# 访问网络

ip netns $pid exec ip route add default dev eth0

iptables -t nat -A POSTROUTING -s $container -j SNAT --to $host

ip netns $pid exec route add default gw $host dev vethC

# 端口映射

iptables -t nat -A PREROUTING -p tcp --dport $port -j DNAT --to-destination $container:80

iptables -t nat -A POSTROUTING -d $container -p tcp --dport 80 -j --to $host
