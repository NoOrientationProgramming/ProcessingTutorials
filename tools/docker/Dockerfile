
FROM ubuntu:22.04

# update
RUN apt update; apt -y upgrade; \
	apt update --fix-missing

# app install
RUN apt -y install sudo \
				git \
				vim \
				netcat \
				telnet \
				build-essential \
				python3 \
				python3-pip \
				mingw-w64 \
				g++-arm-linux-gnueabihf \
				cmake; \
	pip3 install \
				meson \
				ninja

RUN update-alternatives --set x86_64-w64-mingw32-g++ \
				/usr/bin/x86_64-w64-mingw32-g++-posix

ENV dirStart="/root/tutorials"
RUN mkdir "$dirStart"
WORKDIR "$dirStart"

