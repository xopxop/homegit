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

***Resources:*** 
+ [learning docker](https://www.linkedin.com/learning/learning-docker-2)

## Mandatory Part
### 00_how_to_docker
#### 01: Create a virtual machine with docker-machine using the virtualbox driver, and named Char.
*Answer:*
```
docker-machine --driver virtualbox Char
```
*Explanation:*
`--driver` flag to indicate which provider (VirtualBox, DigitalOcean, AWS, etc.) that machine should be created on, and an argument behind to indicate the name of the created machine.

*Result:*
run `docker-machine ls` to list all the created machine, created machine named `Char` should be in the list

*NOTE:*
To get farmiliar with the `docker-machine` command, run:
```
$ docker-machine --help
```
or documents at [docker-machine create](https://docs.docker.com/machine/reference/create/)

#### 02: Get the IP address of the Char virtual machine
*Answer:*
```
docker-machine ip Char
```
*Explaination*
```
ip      Get the IP address of a machine
```
*Result*
```
an IP address from Char machine
```

#### 03: Define the variables needed by your virtual machine Char in the general env of your terminal, so that you can run the docker ps command without errors. You have to fix all four environment variables with one command, and you are not allowed to use your shell’s builtin to set these variables by hand.
*Answer:*
```
eval $(docker-machine env Char)
```

*Explanation:*
You can check if your shell connect to the new machine by listing all the docker machine `docker-machine ls`. At the Collum "ACTIVE" if `-` means your shell doesnt connect, `*` mean connects
So how to make your shell connect, by channging or adding the env variable to our enviroment. In or der to list the enviroment of the created machine Char, we run the command `docker-machine env Char`,it will display the commands to set up the enviroment for the Docker client
For example:
```
export DOCKER_TLS_VERIFY="1"
export DOCKER_HOST="tcp://192.168.99.103:2376"
export DOCKER_CERT_PATH="/home/duthan/.docker/machine/machines/Char"
export DOCKER_MACHINE_NAME="Char"
# Run this command to configure your shell: 
# eval $(docker-machine env Char)
```
run `eval $(docker-machine env Char)` to add the variables to our enviroment.