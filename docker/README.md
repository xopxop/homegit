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
docker exec Abathur echo 'from flask import Flask\napp = Flask(__name__)\n@app.route("/")\ndef hello_world():\n\treturn "<h1>Hello, World!</h1>"' > /root/app.py
docker exec -e FLASK_APP=/root/Abathur/app.py Abathur flask run --host=0.0.0.0 --port 3000
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

____________________________________________________________________

#### 20: Create a local swarm, the Char virtual machine should be its manager.
*Answer:*
```
docker swarm init --advertise-addr $(docker-machine ip Char)
```

*Explaination:*
From [Creat a swarm](https://docs.docker.com/engine/swarm/swarm-tutorial/create-swarm/):
docker swarm init --advertise-addr <MANAGER-IP>

*Result:*
A message of the initializing displays

#### 21: Create another virtual machine with docker-machine using the virtualbox driver, and name it Aiur
*Answer:*
```
docker-machine create --driver virtualbox Aiur
```

*Explaination:*
Same as Question 1

*Results:*
Auir is listed in the out-put `docker-machine ls`

#### 22: Turn Aiur into a slave of the local swarm in which Char is leader (the command to take control of Aiur is not requested).
*Answer:*
```
docker-machine ssh Aiur "docker swarm join --token $(docker swarm join-token worker -q) $(docker-machine ip Char):2377"
```

*Explaination:*
docker-machine ssh Aiur                          log in to Aiur
docker swarm join --token $(docker swarm join-token worker -q) $(docker-machine ip Char):2377
[add nodes](https://docs.docker.com/engine/swarm/swarm-tutorial/add-nodes/)

*Result:*
```
docker node ls
```

#### 23: Create an overlay-type internal network that you will name overmind.
*Answer:*
```
docker network create -d overlay overmind
```
*Explaination:*
network                     Manage networks
create                      Create a network
-d, --driver string         Driver to manage the Network (default "bridge")

*Result:*
overmind is now listed in the network `docker network ls`

#### 24: Launch a rabbitmq SERVICE that will be named orbital-command. You should define a specific user and password for the RabbitMQ service, they can be whatever you want. This service will be on the overmind network.
*Answer:*
```
docker service create -d --network overmind --name orbital-command -e RABBITMQ_DEFAULT_USER=root -e RABBITMQ_DEFAULT_PASS=root rabbitmq
```

*Explaination:*
service                     Manage services
create                      Create a new service
-d, --detach                Exit immediately instead of waiting for the service to converge
--network network           Network attachments
--name string               Service name
-e, --env list              Set environment variables
From [rabbitmq](https://hub.docker.com/_/rabbitmq/)
```
Setting default user and password
If you wish to change the default username and password of guest / guest, you can do so with the RABBITMQ_DEFAULT_USER and RABBITMQ_DEFAULT_PASS environmental variables:
```

*Result:*
`docker service ls`

#### 25: List all the services of the local swarm.
*Answer:*
```
docker service ls
```

#### 26: Launch a 42school/engineering-bay service in two replicas and make sure that the service works properly (see the documentation provided at hub.docker.com). This service will be named engineering-bay and will be on the overmind network.
*Answer:*
```
docker service create -d --network overmind --name engineering-bay --replicas 2 -e OC_USERNAME=root -e OC_PASSWD=root 42school/engineering-bay
```

*Explaination:*
service                     Manage services
create                      Create a new service
-d, --detach                Exit immediately instead of waiting for the service to converge
--network network           Network attachments
--name string               Service name
--replicas uint             Number of tasks
-e, --env list                           Set environment variables
From [engineering/bay](https://hub.docker.com/r/42school/engineering-bay/)
+ OC_USERNAME : Username used to access to orbital-command
+ OC_PASSWD : Password used to access to orbital-command

*Result:*
`docker service ls`

#### 27: Get the real-time logs of one the tasks of the engineering-bay service.
*Answer:*
```
docker service logs -f $(docker service ps engineering-bay -f "name=engineering-bay.1" -q)
```

*Explaination:*
logs        Fetch the logs of a service or task
-f, --follow         Follow log output
In `(docker service ps engineering-bay -f "name=engineering-bay.1" -q)`
ps          List the tasks of one or more services
-f, --filter filter   Filter output based on conditions provided
-q, --quiet           Only display task IDs
[docker service ps](https://docs.docker.com/engine/reference/commandline/service_ps/)

*Result:*
Real-time logs of tast 1 of the engineering-bay service

#### 28: ... Damn it, a group of zergs is attacking orbital-command, and shutting down the engineering-bay service won’t help at all... You must send a troup of Marines to eliminate the intruders. Launch a 42school/marine-squad in two replicas, and make sure that the service works properly (see the documentation provided at hub.docker.com). This service will be named... marines and will be on the overmind network.
*Answer:*
```
docker service create -d --name marines --network overmind --replicas 2 -e OC_USERNAME=root -e OC_PASSWD=root 42school/marine-squad
```

*Explaination:*
[42school/marine-squad](https://hub.docker.com/r/42school/marine-squad)
+ OC_USERNAME : Username used to access to orbital-command
+ OC_PASSWD : Password used to access to orbital-command

*Result:*
`docker service ls`

#### 29: Display all the tasks of the marines service.
*Answer:*
```
docker service ps marines
```

*Explaination:*
ps                  List the tasks of one or more services

*Result:*
Tasks of marines service

#### 30: Increase the number of copies of the marines service up to twenty, because there’s never enough Marines to eliminate Zergs. (Remember to take a look at the tasks and logs of the service, you’ll see, it’s fun.)
*Answer:*
```
docker service scale -d marines=20
```

*Explaination:*
scale           Scale one or multiple replicated services
-d, --detach    Exit immediately instead of waiting for the service to converge

*Result:*
`docker service ps marines`
There is 20 marines

#### 31: Force quit and delete all the services on the local swarm, in one command.
*Answer:*
```
docker service rm $(docker service ls -q)
```

*Explaination:*
-q, --quiet           Only display IDs

*Result:*
`docker service ls`

#### 32: Force quit and delete all the containers (whatever their status), in one command.
*Answer:*
```
docker rm -f $(docker ps -a -q)
```

*Explaination:*
docker rm           Remove one or more containers
-f, --force         Force the removal of a running container (uses SIGKILL)
docker ps           List containers
-a, --all           Show all containers (default shows just running)
-q, --quiet         Only display numeric IDs

*Result:*
`docker ps`

#### 33: Delete all the container images stored on the Char virtual machine, in one command as well.
*Answer:*
```
docker rmi $(docker images -a -q)
```

*Explaination:*
rmi                 Remove one or more images
-a, --all           Show all images (default hides intermediate images)
-q, --quiet         Only show numeric IDs

*Result:*
`docker images -a`

#### 34: Delete the Aiur virtual machine without using rm -rf
*Answer:*
```
docker-machine rm -y Aiur
```

*Explaination:*
rm           Remove a machine
-y           Assumes automatic yes to proceed with remove, without prompting further user confirmation

*Result:*
docker-machine ls

### Dockerfiles
Resouces:
+ [Dockerfile reference](https://docs.docker.com/engine/reference/builder/)
+ ex00: [Alpine Linux package management](https://wiki.alpinelinux.org/wiki/Alpine_Linux_package_management)
#### Excercise 00: vim/emacs
**From an alpine image you’ll add to your container your favorite text editor, vim oremacs, that will launch along with your container.**
*How to test:*
```
docker build -t ex00 .
docker run --rm -it ex00
```
*Note:* [How Dockerfile naming works?](https://stackoverflow.com/questions/35511604/docker-unable-to-prepare-context-unable-to-evaluate-symlinks-in-dockerfile-pat)

#### Excercise 01: BYOTSS
**From a debian image you will add the appropriate sources to create a TeamSpeak server, that will launch along with your container. It will be deemed valid if at least one user can connect to it and engage in a normal discussion (no far-fetched setup), so be sure to create your Dockerfile with the right options. Your program should get the sources when it builds, they cannot be in your repository.**
*Explaination:*
```
FROM debian                 ----> from debian image

MAINTAINER DuThan <dthan@student.hive.fi>                   ----> Producer

ENV TS3SERVER_LICENSE=accept                ----> set variable "TS3SERVER_LICENSE = accept"

WORKDIR /home/teamspeak                     ----> work directory

EXPOSE 9987/udp 10011 30033                 ----> open ports

RUN apt-get update && \
apt-get upgrade -y && \
apt-get install -y wget bzip2 && \
wget http://dl.4players.de/ts/releases/3.0.13.4/teamspeak3-server_linux_amd64-3.0.13.4.tar.bz2 && \
tar -xvf teamspeak3-server_linux_amd64-3.0.13.4.tar.bz2

WORKDIR teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh
```
Resources:
+ [Dockerhub/TeamSpeak](https://hub.docker.com/_/teamspeak)
+ https://www.youtube.com/watch?v=za65VWo29uQ

#### Excercise 02: Dockerfile in a Dockerfile... in a Dockerfile ?
**You are going to create your first Dockerfile to containerize Rails applications. That’s a special configuration: this particular Dockerfile will be generic, and called in another Dockerfile, that will look something like this:**
```
FROM ft-rails:on-build
EXPOSE 3000
CMD ["rails", "s", "-b", "0.0.0.0", "-p", "3000"]
```
**Your generic container should install, via a ruby container, all the necessary dependencies and gems, then copy your rails application in the /opt/app folder of your container. Docker has to install the approtiate gems when it builds, but also launch the migrations and the db population for your application. The child Dockerfile should launch the rails server (see example below). If you don’t know what commands to use, it’s high time to look at the Ruby on Rails documentation.**

#### Excercise 03: Exercise 03: ... and bacon strips ... and bacon strips ...
**Docker can be useful to test an application that’s still being developed without polluting your libraries. You will have to design a Dockerfile that gets the development version of Gitlab - Community Edition installs it with all the dependencies and the necessary configurations, and launches the application, all as it builds. The container will be deemed valid if you can access the web client, create users and interact via GIT with this container (HTTPS and SSH). Obviously, you are not allowed to use the official container from Gitlab, it would be a shame...**
