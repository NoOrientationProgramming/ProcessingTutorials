
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
				cmake; \
	pip3 install \
				meson \
				ninja

ENV dirStart="/root/tutorials"

RUN mkdir "$dirStart"
WORKDIR "$dirStart"

