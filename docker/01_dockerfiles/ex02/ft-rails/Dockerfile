##########################################################################################
#                                     Exercise 02                                        #
##########################################################################################
#               Exercise 02: Dockerfile in a Dockerfile... in a Dockerfile ?             #
# Turn-in directory : ex02/                                                              #
# Files to turn in : Dockerfile                                                          #
# Allowed functions : -                                                                  #
# Notes : n/a                                                                            #
##########################################################################################

# You are going to create your first Dockerfile to containerize Rails applications. That’s
# a special configuration: this particular Dockerfile will be generic, and called in another
# Dockerfile, that will look something like this:

# FROM ft-rails:on-build
# EXPOSE 3000
# CMD ["rails", "s", "-b", "0.0.0.0", "-p", "3000"]

# Your generic container should install, via a ruby container, all the necessary depen-
# dencies and gems, then copy your rails application in the /opt/app folder of your
# container. Docker has to install the approtiate gems when it builds, but also launch
# the migrations and the db population for your application. The child Dockerfile should
# launch the rails server (see example below). If you don’t know what commands to use,
# it’s high time to look at the Ruby on Rails documentation.

FROM ruby:latest

MAINTAINER Du Than <dthan@student.hive.fi>

RUN apt-get update -y && apt-get install -y \
        build-essential \
        libpq-dev \
        nodejs \
        sqlite3
RUN gem install bundler --no-document
RUN gem install rails --no-document
RUN gem install rake -v 12.3.1 --no-document

ONBUILD COPY app /opt/app/
ONBUILD WORKDIR /opt/app/

ONBUILD EXPOSE 3000
ONBUILD RUN bundle install
ONBUILD RUN rake _12.3.1_ db:migrate
ONBUILD RUN rake _12.3.1_ db:seed
ONBUILD RUN rake _12.3.1_