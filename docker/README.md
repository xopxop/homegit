# Docker-1
## Introduction
*What Is Docker/ What Docker Does?*
+ Carves up a computer into sealed containers that run your code
+ Gets the code to and from your computers
+ Build these containers for you
+ Is a social platform for you to find and share containers, which are different from virtual machines
<image src="Pictures/Docker.png" width = 310 height = 248 >

*What is a Container?*
+ A self-container sealed unit of software
+ Contains everything required to run the code
+ Includes batteries and operating system

*A conatiner includes:*
+ Code
+ Config
+ Processes (within that container)
+ Networking (allow containers to talk to the other containers which are allowed)
+ Dependencies (that system need bounded in that container)
+ OS (just enough to run your code)

The way it works is it tales all the services that make up the Linux server (Networking, storage, code, inter process communication, the whole works) and it makes a copy of that in the Linux Kernel for each containers. So, each containers has its own little world that it can't see out of and other container can't see in.
Resources: 
+ [learning docker](https://www.linkedin.com/learning/learning-docker-2)

