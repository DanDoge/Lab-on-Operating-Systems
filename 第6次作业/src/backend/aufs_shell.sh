echo container name is $1
echo and its ip address is $2
mkdir /var/lib/lxc/${1}
mkdir /var/lib/lxc/${1}_diff
echo mount -t aufs -o br=/var/lib/lxc/${1}_diff=rw:/var/lib/lxc/base=ro newnone /var/lib/lxc/${1}
mount -t aufs -o br=/var/lib/lxc/${1}_diff=rw:/var/lib/lxc/base=ro newnone /var/lib/lxc/${1}
rm /var/lib/lxc/${1}/config
cat << EOF > /var/lib/lxc/${1}/config
# Template used to create this container: /usr/share/lxc/templates/lxc-ubuntu
# Parameters passed to the template:
# Template script checksum (SHA-1): 4d7c613c3c0a0efef4b23917f44888df507e662b
# For additional config options, please look at lxc.container.conf(5)
# Uncomment the following line to support nesting containers:
#lxc.include = /usr/share/lxc/config/nesting.conf
# (Be aware this has security implications)
# Common configuration
lxc.include = /usr/share/lxc/config/ubuntu.common.conf
# Container specific configuration
lxc.rootfs = /var/lib/lxc/${1}/rootfs
lxc.rootfs.backend = dir
lxc.utsname = ${1}
lxc.arch = amd64
# Network configuration
lxc.network.type = veth
lxc.network.name = eth0
lxc.network.link = lab6br0
lxc.network.ipv4 = 172.16.100.${2}/24
lxc.network.ipv4.gateway = 172.16.100.1
lxc.network.veth.pair = ${1}
lxc.network.flags = up
EOF
rm /var/lib/lxc/${1}/rootfs/etc/hostname
cat << EOF > /var/lib/lxc/${1}/rootfs/etc/hostname
${1}
EOF
lxc-start -n ${1}
