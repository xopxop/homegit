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

FROM ruby:2.5.1

MAINTAINER Du Than <dthan@student.hive.fi>

RUN apt-get update && apt-get install -y nodejs && rm -rf /var/lib/apt/lists/*
RUN gem install rails bundler:1.17.3

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD RUN bundler install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed

# Step 1: Setting up
# mkdir ft-rails
# mv Dockerfile ft-rails
# Step 2: Dowloading app
# git clone https://bitbucket.org/railstutorial/sample_app_4th_ed.git app
# Step 3: Create Dockerfile for ex02
# echo -e 'FROM ft-rails:on-build\nEXPOSE 3000\nCMD ["rails", "s", "-b", "0.0.0.0", "-p" ,"3000"]' > Dockerfile

# How to run
# build the ft-rails:onbuild
# docker build -t ft-rails:on-build .
# docker build -t ex02 .
# docker run -it --rm -p 3000:3000 ex02