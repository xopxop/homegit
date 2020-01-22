# Roger-skyline-1 INTRODUCTION
roger-skyline-1 let you install a Virtual Machine, discover the
basics about system and network administration as well as a lots of services used on a
server machine.
# VM Part
You have to run a Virtual Machine (VM) with the Linux OS of your choice (Debian
Jessie, CentOS 7...) in the hypervisor of your choice (VMWare Fusion, VirtualBox...).
• A disk size of 8 GB.
• Have at least one 4.2 GB partition.
• It will also have to be up to date as well as the whole packages installed to meet
the demands of this subject.
```
My VM (set-up)
+ DEBIAN 10.2
+ Disk size of 8GB
+ one partition with 4.2 GB
In order to check for the size of disk, run the command: 
sudo fdisk -l
Note: when partioning the disk size, the primary disk should be some where around 4.5G, therefore when fdisk, the system disk will be around 4.2GB
because the size when partioning and the one which was shown by the system is different
https://superuser.com/questions/217012/what-size-should-i-make-a-partition-to-appear-as-a-standard-number-e-g-100gb
```
# Network and Security Part
For the network on your VM, here are the steps to achieve:
• You must create a non-root user to connect to the machine and work.
```
non-root user: dthan
```
• Use sudo, with this user, to be able to perform operation requiring special rights.
```
In order to use sudo command, first we have to install as root user:
$ su
# apt-get update -y && apt-get upgrade -y
# apt-get install sudo
Optional: Install vim
# apt-get install vim
```
