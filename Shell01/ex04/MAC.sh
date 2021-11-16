ifconfig -a link | grep ether | awk -F' ' '{print $NF}'
