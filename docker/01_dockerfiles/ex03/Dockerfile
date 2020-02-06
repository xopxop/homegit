############################################################################################
#                                       Exercise 03                                        #
############################################################################################
#                 Exercise 03: ... and bacon strips ... and bacon strips ...               #
# Turn-in directory : ex03/                                                                #
# Files to turn in : Dockerfile                                                            #
# Allowed functions : -                                                                    #
# Notes : n/a                                                                              #
############################################################################################

# Docker can be useful to test an application that’s still being developed without pol-
# luting your libraries. You will have to design a Dockerfile that gets the development
# version of Gitlab - Community Edition installs it with all the dependencies and the nec-
# essary configurations, and launches the application, all as it builds. The container will be
# deemed valid if you can access the web client, create users and interact via GIT with this
# container (HTTPS and SSH). Obviously, you are not allowed to use the official container
# from Gitlab, it would be a shame...

FROM ubuntu:latest

MAINTAINER Du Than <dthan@student.hive.fi>

RUN apt-get update && apt-get upgrade -y && \
	apt-get install -y ca-certificates openssh-server wget postfix
RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && chmod 777 script.deb.sh && ./script.deb.sh && apt-get install -y gitlab-ce
RUN apt update && apt install -y tzdata && \
  apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null
