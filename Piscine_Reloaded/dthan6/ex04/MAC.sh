ifconfig -a | grep ether | cut -d ' ' -f 2 | sed 2d
