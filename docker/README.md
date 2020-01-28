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

*Explaination:*
ip      Get the IP address of a machine

*Result:*
an IP address from Char machine

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

*Result:*
Command `docker ps` works

#### 04: Get the hello-world container from the Docker Hub, where it’s available.
*Answer:*
```
docker pull hello-world
```
*Explaination:*

To get the hello-world container, we need to pull it from the Docker Hub by using the command `Docker pull <container_image>`

*Results:*

`hello-world` is listed in the images `docker image ls`

#### 05: Launch the hello-world container, and make sure that it prints its welcome message, then leaves it.
*Answer:*
```
docker run hello-world
```

*Explaination:*

From: docker --help
run         Run a command in a new container

*Expected Result:*

Text message from Docker

#### 06: Launch an nginx container, available on Docker Hub, as a background task. It should be named overlord, be able to restart on its own, and have its 80 port attached to the 5000 port of Char. You can check that your container functions properly by visiting http://<ip-de-char>:5000 on your web browser.
*Answer:*
```
docker run -d -p 5000:80 --name overlord --restart=always nginx
```

*Explaination:*

From: `docker run --help` or `man docker run`
-d: Run container in background
-p: Publish a container's port, or range of ports, to the host HOST_PORT:CONTAINER_PORT
--name string: Assign a name to the container
--restart string: Restart policy to apply when a container exits (default "no")
**restart policy:***
+ no            : Do not automatically restart the container when it exits
+ on-failure    : Restart only if the container exits with a non-zero exit status. Optionally, linit the number of restart retries the Docker daemon attemps.
+ always        : Always restart the container regardless of the exit status. When you specify always, the Docker daemon will try to restart the container indefinitely. The container will also always start on daemon startup, regardless of the current state of the container.
+ unless-stopped: Always restart the container regardless of the exit status, but do not start it on daemon startup if the container has been put to a stopped state before.

*Result:*

Visiting http://<ip-de-char>:5000 on your web browser with nginx page.

#### 07: Get the internal IP address of the overlord container without starting its shell and in one command
*Answer:*
```
docker inspect -f '{{.NetworkSettings.IPAddress}}' overlord
```

*Explaination:*
inspect : Return low-level information on Docker objects
-f      : Format the output using the give Go template

*Result:*
The internal IP address of the overlord container

#### 08: Launch a shell from an alpine container, and make sure that you can interact directly with the container via your terminal, and that the container deletes itself once the shell’s execution is done
*Answer:*
```
docker run -it --rm alpine /bin/sh
```

*Explaination:*
-i, --interactive       Keep STDIN open even if not attached
-t, --tty               Allocate a pseudo-TTY
--rm                    Automatically remove the container when it exits
Note: [Starting a shell in the Docker Alpine container](https://stackoverflow.com/questions/35689628/starting-a-shell-in-the-docker-alpine-container/43564198#43564198)

*Results:*
Runing a shell from the alpine container via your terminal

#### 09: From the shell of a debian container, install via the container’s package manager everything you need to compile C source code and push it onto a git repo (of course, make sure before that the package manager and the packages already in the container are updated). For this exercise, you should only specify the commands to be run directly in the container.
*Answer:*
```
apt-get update -y && apt-get upgrade -y && apt-get install build-essential git -y 
```

*Explaination:*
To run the answer command line, we need to run in our debian container `docker run -it --rm debian`
build-essential: contains gcc/g++ compilers and libraries and some other utilities

*Result:*
a debian machine with the build-essential package and git

#### 10: Create a volume named hatchery.
*Answer:*
```
docker volume create hatchery
```

*Explaination:*
From: docker volume --help
create: Create a volume

*Result:*
hatchery was listed in the output `docker volume ls`

#### 11: List all the Docker volumes created on the machine. Remember. VOLUMES
*Answer:*
```
docker volume ls
```

*Explaination:*
ls: List volumes

*Result:*
Listed volumes

#### 12: Launch a mysql container as a background task. It should be able to restart on its own in case of error, and the root password of the database should be Kerrigan. You will also make sure that the database is stored in the hatchery volume, that the container directly creates a database named zerglings, and that the container itself is named spawning-pool
*Answer:*
```
docker run -d --name spawning-pool --restart=on-failure:10 -e MYSQL_ROOT_PASSWORD=Kerrigan -e MYSQL_DATABASE=zerglings -v hatchery:/var/lib/mysql mysql --default-authentication-plugin=mysql_native_password
```
*Explaination:*
-d, --detach                         Run container in background and print container ID
--name string                        Assign a name to the container
--restart policy                     Restart policy to apply when a container exits. Supported values are:
┌─────────────────────────┬───────────────────────────────────┐
│Policy                   │ Result                            │
├─────────────────────────┼───────────────────────────────────┤
│no                       │ Do not automatically restart the  │
│                         │ container when it exits.          │
├─────────────────────────┼───────────────────────────────────┤
│on-failure[:max-retries] │ Restart only if the container     │
│                         │ exits with a non-zero exit        │
│                         │ status. Optionally, limit the     │
│                         │ number of restart retries the     │
│                         │ Docker daemon attempts.           │
├─────────────────────────┼───────────────────────────────────┤
│always                   │ Always restart the container      │
│                         │ regardless of the exit status.    │
│                         │ When you specify always, the      │
│                         │ Docker daemon will try to restart │
│                         │ the container indefinitely. The   │
│                         │ container will also always start  │
│                         │ on daemon startup, regardless of  │
│                         │ the current state of the          │
│                         │ container.                        │
├─────────────────────────┼───────────────────────────────────┤
│unless-stopped           │ Always restart the container      │
│                         │ regardless of the exit status,    │
│                         │ but do not start it on daemon     │
│                         │ startup if the container has been │
│                         │ put to a stopped state before.    │
└─────────────────────────┴───────────────────────────────────┘
-e, --env list                       Set environment variables
-v, --volume list                    Bind mount a volume
mysql --default-authentication-plugin=mysql_native_password
Read here for me detail![native pluggable authentification](https://dev.mysql.com/doc/refman/8.0/en/native-pluggable-authentication.html)

*Result:*
pulling msq into the images `docker images ls`
create a container named "spawning-pool" listed in `docker ps`

#### 13: Print the environment variables of the spawning-pool container in one command, to be sure that you have configured your container properly
*Answer:*
```
docker inspect -f '{{.Config.Env}}' spawning-pool
```
*Explaination:*
the same to **Question 07**

*Result:*
[MYSQL_ROOT_PASSWORD=Kerrigan MYSQL_DATABASE=zerglings PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin GOSU_VERSION=1.7 MYSQL_MAJOR=8.0 MYSQL_VERSION=8.0.19-1debian9]

#### 14:Launch a wordpress container as a background task, just for fun. The container should be named lair, its 80 port should be bound to the 8080 port of the virtual machine, and it should be able to use the spawning-pool container as a database service. You can try to access lair on your machine via a web browser, with the IP address of the virtual machine as a URL. Congratulations, you just deployed a functional Wordpress website in two commands!
*Answer:*
```
docker run -d --name lair -p 8080:80 --link spawning-pool:mysql wordpress
```
*Explaination:*
--link=name-or-id[:alias]
Add link to another container:
If the operator uses --link when starting the new client container, then the client
container can access the exposed port via a private networking interface. Docker will set
some environment variables in the client container to help indicate which interface and
port to use.

*Result:*
logging-in wordpress page with the ip_address:8080

#### 15: Launch a phpmyadmin container as a background task. It should be named roach-warden, its 80 port should be bound to the 8081 port of the virtual machine and it should be able to explore the database stored in the spawning-pool container.
*Answer:*
```
docker run -d --name roach-warden -p 8081:80 --link spawning-pool:db phpmyadmin/phpmyadmin
```

*Explaination:*
phpmyadmin/phpmyadmin
[Official phpMyAdmin Docker image](https://hub.docker.com/r/phpmyadmin/phpmyadmin)

*Result:*
phpMyadmin page : <ip>:8081

#### 16: Look up the spawning-pool container’s logs in real time without running its shell.
*Answer:*
```
docker logs -f spawning-pool
```

*Explaination:*
From `docker help --help`
 -f, --follow         Follow log output

*Result:*
spawning-pool container's logs in realtime without running its shell

#### 17: Display all the currently active containers on the Char virtual machine.
*Answer:*
```
docker ps
```

*Explaination:*
docker ps - List containers

*Result:*
Active containers on the Char virtual machine

#### 18: Relaunch the overlord container
*Answer:*
```
docker restart overlord
```
*Explaination:*
restart     Restart one or more containers

*Result:*
overlord container restared, time on STATUS changed

#### 19: Launch a container name Abathur. It will be a Python container, 2-slim version, its /root folder will be bound to a HOME folder on your host, and its 3000 port will be bound to the 3000 port of your virtual machine. You will personalize this container so that you can use the Flask micro-framework in its latest version. You will make sure that an html page displaying "Hello World" with \<h1\> tags can be served by Flask. You will test that your container is properly set up by accessing, via curl or a web browser, the IP address of your virtual machine on the 3000 port. You will also list all the necessary commands in your repository
*Answer:*
```
docker run --name Abathur -v ~/:/root -p 3000:3000 -dit python:2-slim
docker exec Abathur pip install Flask
echo 'from flask import Flask\napp = Flask(__name__)\n@app.route("/")\ndef hello_world():\n\treturn "<h1>Hello, World!</h1>"' > ~/app.py
docker exec -e FLASK_APP=/root/app.py Abathur flask run --host=0.0.0.0 --port 3000
```

*Explaination:*
```
docker run --name Abathur python: -v ~/:/root -p 3000:3000 -dit python:2-slim
```
-v|--volume[=[[HOST-DIR:]CONTAINER-DIR[:OPTIONS]]]
          Create a bind mount. If you specify, -v /HOST-DIR:/CONTAINER-DIR, Docker
          bind mounts /HOST-DIR in the host to /CONTAINER-DIR in the Docker
          container. If 'HOST-DIR' is omitted,  Docker automatically creates the new
          volume on the host. For more info[Docker run reference](https://docs.docker.com/engine/reference/run/)
[python version](https://hub.docker.com/_/python]
-dit : Run container in background and print container ID, Keep STDIN open even if not attached, Allocate a pseudo-TTY
```
docker exec Abathur pip install Flask
```
exec        Run a command in a running container
pip         The pip command is a tool for installing and managing Python packages
[flask instalation](https://flask.palletsprojects.com/en/1.0.x/installation/#installation)
```
docker exec -e FLASK_APP=/root/app.py Abathur flask run --host=0.0.0.0 --port 3000
```
-e, --env list             Set environment variables

*Result:*