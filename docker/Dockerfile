
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

ENV versLibz="v1.2.13" \
	versLibssl="1_1_1t" \
	versLibcurl="7.88.1" \
	versLibjsoncpp="1.9.5"

ENV toolDir="/opt/tools" \
	buildDir="/opt/dependencies-build"

ENV PATH="$toolDir:$PATH"

# directories
RUN mkdir /home/$user/build; \
	mkdir ${buildDir}; \
	mkdir ${buildDir}/zlib; \
	mkdir ${buildDir}/zlib/build; \
	mkdir ${buildDir}/zlib/build/native; \
	mkdir ${buildDir}/zlib/build/win64; \
	mkdir ${buildDir}/zlib/build/rpi; \
	mkdir ${buildDir}/openssl; \
	mkdir ${buildDir}/openssl/build; \
	mkdir ${buildDir}/openssl/build/native; \
	mkdir ${buildDir}/openssl/build/win64; \
	mkdir ${buildDir}/openssl/build/rpi; \
	mkdir ${buildDir}/curl; \
	mkdir ${buildDir}/curl/build; \
	mkdir ${buildDir}/curl/build/native; \
	mkdir ${buildDir}/curl/build/win64; \
	mkdir ${buildDir}/curl/build/rpi; \
	mkdir ${buildDir}/jsoncpp; \
	mkdir ${buildDir}/jsoncpp/build; \
	mkdir ${buildDir}/jsoncpp/build/native; \
	mkdir ${buildDir}/jsoncpp/build/win64; \
	mkdir ${buildDir}/jsoncpp/build/rpi

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
				libxrandr-dev \
				libxinerama-dev \
				libxcursor-dev \
				libxi-dev \
				wayland-protocols \
				libwayland-dev \
				bison \
				flex \
				libgd-dev \
				libwebp-dev \
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

# zlib
WORKDIR zlib

RUN git clone https://github.com/madler/zlib.git zlib-${versLibz}
WORKDIR zlib-${versLibz}
RUN git checkout ${versLibz}

WORKDIR ../build

WORKDIR native
RUN ../../zlib-${versLibz}/configure --static; \
	make -j; make install
WORKDIR ..

WORKDIR win64
RUN CC=$prefixMinGw-gcc AR=$prefixMinGw-ar RANLIB=$prefixMinGw-ranlib \
	../../zlib-${versLibz}/configure --static --prefix=$prefixMinGwDir; \
	make -j; make install
WORKDIR ..

WORKDIR rpi
RUN CC=$prefixRpi-gcc AR=$prefixRpi-ar RANLIB=$prefixRpi-ranlib \
	../../zlib-${versLibz}/configure --static --prefix=$prefixRpiDir; \
	make -j; make install
WORKDIR ..

WORKDIR ../..

# openssl
WORKDIR openssl

RUN git clone https://github.com/openssl/openssl.git OpenSSL_${versLibssl}
WORKDIR OpenSSL_${versLibssl}
RUN git checkout OpenSSL_${versLibssl}

WORKDIR ../build

WORKDIR native
RUN ../../OpenSSL_${versLibssl}/Configure linux-x86_64 no-ssl2 no-shared --prefix=$prefixNativeDir; \
	make -j; make install_sw
WORKDIR ..

WORKDIR win64
RUN ../../OpenSSL_${versLibssl}/Configure mingw64 no-ssl2 no-shared --prefix=$prefixMinGwDir --cross-compile-prefix=$prefixMinGw-; \
	make -j; make install_sw
WORKDIR ..

WORKDIR rpi
RUN ../../OpenSSL_${versLibssl}/Configure linux-generic32 no-ssl2 no-shared --prefix=$prefixRpiDir --cross-compile-prefix=$prefixRpi-; \
	make -j; make install_sw
WORKDIR ..

WORKDIR ../..

# curl
WORKDIR curl

RUN git clone https://github.com/curl/curl.git curl-${versLibcurl}
WORKDIR curl-${versLibcurl}
RUN git checkout curl-$(echo "$versLibcurl" | sed "s:\.:_:g"); \
	autoreconf -fi

WORKDIR ../build

ENV cross="$prefixNative" \
	crossDir="$prefixNativeDir"

WORKDIR native
RUN \
	CC="$cross-gcc" \
	AS="$cross-as" \
	LD="$cross-ld" \
	NM="$cross-nm" \
	AR="$cross-ar" \
	RANLIB="$cross-ranlib" \
	LDFLAGS="-static" \
	CFLAGS="-static-libgcc" \
	CXXFLAGS="-static-libstdc++" \
	PKG_CONFIG="$cross-pkg-config --static" \
	../../curl-${versLibcurl}/configure \
	--enable-static \
	--enable-http-auth \
	--disable-shared \
	--with-openssl \
	--without-brotli \
	--build=x86_64-linux-gnu \
	--host="$cross" \
	--prefix="$crossDir"; \
	make -j; make install
WORKDIR ..

ENV cross="$prefixMinGw" \
	crossDir="$prefixMinGwDir"

WORKDIR win64
RUN \
	CC="$cross-gcc" \
	AS="$cross-as" \
	LD="$cross-ld" \
	NM="$cross-nm" \
	AR="$cross-ar" \
	RANLIB="$cross-ranlib" \
	LDFLAGS="-static" \
	CFLAGS="-static-libgcc" \
	CXXFLAGS="-static-libstdc++" \
	PKG_CONFIG="$cross-pkg-config --static" \
	LIBS="-lcrypt32" \
	../../curl-${versLibcurl}/configure \
	--enable-static \
	--enable-http-auth \
	--disable-shared \
	--with-openssl \
	--without-brotli \
	--build=x86_64-linux-gnu \
	--host="$cross" \
	--prefix="$crossDir" \
	--with-schannel \
	--with-default-ssl-backend=schannel; \
	make -j; make install
WORKDIR ..

ENV cross="$prefixRpi" \
	crossDir="$prefixRpiDir"

WORKDIR rpi
RUN \
	CC="$cross-gcc" \
	AS="$cross-as" \
	LD="$cross-ld" \
	NM="$cross-nm" \
	AR="$cross-ar" \
	RANLIB="$cross-ranlib" \
	LDFLAGS="-static" \
	CFLAGS="-static-libgcc" \
	CXXFLAGS="-static-libstdc++" \
	PKG_CONFIG="$cross-pkg-config --static" \
	../../curl-${versLibcurl}/configure \
	--enable-static \
	--enable-http-auth \
	--disable-shared \
	--with-openssl \
	--without-brotli \
	--build=x86_64-linux-gnu \
	--host="$cross" \
	--prefix="$crossDir"; \
	make -j; make install
WORKDIR ..

WORKDIR ../..

# tclap
RUN cp -r /usr/include/tclap/ $prefixMinGwDir/include/.; \
	cp /usr/lib/x86_64-linux-gnu/pkgconfig/tclap.pc $prefixMinGwDir/lib/pkgconfig/.; \
	sed -i "s:usr:usr/$prefixMinGw:g" $prefixMinGwDir/lib/pkgconfig/tclap.pc

RUN cp -r /usr/include/tclap/ $prefixRpiDir/include/.; \
	cp /usr/lib/x86_64-linux-gnu/pkgconfig/tclap.pc $prefixRpiDir/lib/pkgconfig/.; \
	sed -i "s:usr:usr/$prefixRpi:g" $prefixRpiDir/lib/pkgconfig/tclap.pc

# jsoncpp
WORKDIR jsoncpp

RUN git clone https://github.com/open-source-parsers/jsoncpp.git jsoncpp-${versLibjsoncpp}
WORKDIR jsoncpp-${versLibjsoncpp}
RUN git checkout ${versLibjsoncpp}

RUN meson ../build/native --default-library static --libdir=lib --includedir=include/jsoncpp --prefix=$prefixNativeDir; \
	meson ../build/win64 --default-library static --libdir=lib --includedir=include/jsoncpp --prefix=$prefixMinGwDir --cross-file /opt/dependencies/build/crosscompile-win64.txt; \
	meson ../build/rpi --default-library static --libdir=lib --includedir=include/jsoncpp --prefix=$prefixRpiDir --cross-file /opt/dependencies/build/crosscompile-rpi.txt

WORKDIR ../build

WORKDIR native
RUN ninja; ninja install
WORKDIR ..

WORKDIR win64
RUN ninja; ninja install
WORKDIR ..

WORKDIR rpi
RUN ninja; ninja install
WORKDIR ..

WORKDIR ../..
