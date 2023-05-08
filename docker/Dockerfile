
FROM ubuntu:22.04

# arguments
ARG user
ARG uid
ARG gid

# user
RUN groupadd --gid $gid $user 2>&1 > /tmp/docker-build.log || echo "Could add user $user to group $gid"

# add user with password "jackson"
RUN useradd -m -u $uid -g $gid -p BsUHWbFZO93Ks -s /bin/bash $user 2>&1 > /tmp/docker-build.log || echo "Could not create user $user"; \
	adduser $user sudo; \
	chown $user:$user /opt/

# environment variables
ENV prefixNative="x86_64-linux-gnu" \
	prefixNativeDir="/usr/local" \
	prefixMinGw="x86_64-w64-mingw32" \
	prefixRpi="arm-linux-gnueabihf"

ENV prefixMinGwDir="/usr/$prefixMinGw" \
	prefixRpiDir="/usr/$prefixRpi"

ENV toolDir="/opt/tools" \
	buildDir="/opt/dependencies-build"

ENV PATH="$toolDir:$PATH"

# directories
RUN mkdir /home/$user/build; \
	mkdir ${buildDir}

# update
RUN apt update; apt -y upgrade; \
	apt update --fix-missing

# app install
RUN apt -y install sudo openssh-client \
				git \
				vim \
				tree \
				ack \
				wget \
				bash-completion \
				fortune cowsay \
				build-essential \
				autoconf \
				libtool \
				pkg-config \
				python3 \
				python3-pip \
				mingw-w64 \
				g++-$prefixRpi \
				libtclap-dev \
				cmake \
				extra-cmake-modules \
				libxkbcommon-dev; \
	pip3 install \
				meson \
				ninja

# tools
ADD tools $toolDir

WORKDIR $toolDir

RUN g++ bin2cpp.cxx -o bin2cpp

# dependencies
ADD dependencies /opt/dependencies

WORKDIR ${buildDir}

RUN update-alternatives --set $prefixMinGw-g++ /usr/bin/$prefixMinGw-g++-posix; \
	ln -sr /usr/bin/python3 /usr/bin/python

