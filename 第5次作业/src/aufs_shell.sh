echo -n "container_name:"

read cont_name

echo -n "diff_path:"

read diff_path

mkdir ${diff_path}

mkdir /var/lib/lxc/${cont_name}

mount -t aufs -o br=${diff_path}=rw:/var/lib/lxc/lab5test1=ro none /var/lib/lxc/${cont_name}

rm /var/lib/lxc/${cont_name}/config

cat << EOF > /var/lib/lxc/${cont_name}/config
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
lxc.rootfs = /var/lib/lxc/${cont_name}/rootfs
lxc.rootfs.backend = dir
lxc.utsname = ${cont_name}
lxc.arch = amd64

# Network configuration
lxc.network.type = veth
lxc.network.name = eth0
lxc.network.link = lab5br0
lxc.network.veth.pair = ${cont_name}
lxc.network.flags = up
EOF

rm /var/lib/lxc/${cont_name}/rootfs/etc/hostname

cat << EOF > /var/lib/lxc/${cont_name}/rootfs/etc/hostname
${cont_name}
EOF


lxc-start -n ${cont_name}
