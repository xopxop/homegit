####################################################################################
#                                Exercise 00                                       #
####################################################################################
#                           Exercise 00: vim/emacs                                 #
# Turn-in directory : ex00/                                                        #
# Files to turn in : Dockerfile                                                    #
# Allowed functions : -                                                            #
# Notes : n/a                                                                      #
####################################################################################

# From an alpine image you’ll add to your container your favorite text editor, vim or
# emacs, that will launch along with your container.

FROM alpine

MAINTAINER Du Than <dthan@student.hive.fi>

RUN apk update && apk upgrade && apk add vim

ENTRYPOINT vim