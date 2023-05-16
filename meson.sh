#!/bin/bash

dirTut="t1_hello-world"

if [ ! -z "$1" ]; then
	inUser="$1"

	echo "User input: $inUser"

	if [ -d "$inUser" ]; then
		dirTut="$inUser"
	else
		dirTut="$(ls -1 | grep "$inUser" | sort | head -n 1)"
	fi
fi

echo "Building tutorial: $dirTut"

if [ ! -d "$dirTut" ]; then
	echo "Could not build tutorial. Wrong directory?"
	exit 1
fi

cd "$dirTut"

if [ ! -d "build-meson-ubuntu" ]; then
	meson setup build-meson-ubuntu
fi
ninja -C build-meson-ubuntu

if [ ! -d "build-meson-windows" ]; then
	meson setup --cross-file ../docker/dependencies/build/crosscompile-win64.txt build-meson-windows

	verMinGw="$(ls -1 /usr/lib/gcc/x86_64-w64-mingw32 | grep posix | tail -1)"

	cp /usr/lib/gcc/x86_64-w64-mingw32/$verMinGw/libgcc_s_seh-1.dll build-meson-windows/.
	cp /usr/lib/gcc/x86_64-w64-mingw32/$verMinGw/libstdc++-6.dll build-meson-windows/.
	cp /usr/x86_64-w64-mingw32/lib/libwinpthread-1.dll build-meson-windows/.
fi
ninja -C build-meson-windows

#if [ ! -d "build-meson-raspberry" ]; then
#	meson setup --cross-file ../docker/dependencies/build/crosscompile-rpi.txt build-meson-raspberry
#fi
#ninja -C build-meson-raspberry

