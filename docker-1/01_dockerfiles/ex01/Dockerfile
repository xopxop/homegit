#########################################################################################
#                                   Exercise 01                                         #
#########################################################################################
#                               Exercise 01: BYOTSS                                     #
# Turn-in directory : ex01/                                                             #
# Files to turn in : Dockerfile + Scripts (if applicable)                               #
# Allowed functions : -                                                                 #
# Notes : n/a                                                                           #
#########################################################################################

# From a debian image you will add the appropriate sources to create a TeamSpeak
# server, that will launch along with your container. It will be deemed valid if at least
# one user can connect to it and engage in a normal discussion (no far-fetched setup), so
# be sure to create your Dockerfile with the right options. Your program should get the
# sources when it builds, they cannot be in your repository.

FROM debian

MAINTAINER Du Than <dthan@student.hive.fi>

ENV TS3SERVER_LICENSE=accept

WORKDIR /home/teamspeak

EXPOSE 9987/udp 10011 30033

RUN apt-get update && \
apt-get upgrade -y && \
apt-get install -y wget bzip2 && \
wget https://files.teamspeak-services.com/releases/server/3.12.0/teamspeak3-server_linux_amd64-3.12.0.tar.bz2 && \
tar -xvf teamspeak3-server_linux_amd64-3.12.0.tar.bz2

WORKDIR teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh

# How to build it?
# docker build -t ex01 .

# How to run it?
# docker run --rm -p 9987:9987/udp -p 10011:10011 -p 30033:30033 ex01