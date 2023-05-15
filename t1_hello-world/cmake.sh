#!/bin/bash

if [ ! -d "build-cmake-ubuntu" ]; then
	mkdir build-cmake-ubuntu
fi
cd build-cmake-ubuntu
cmake ..
make
cd ..

if [ ! -d "build-cmake-windows" ]; then
	mkdir build-cmake-windows

	verMinGw="$(ls -1 /usr/lib/gcc/x86_64-w64-mingw32 | grep posix | tail -1)"

	cp /usr/lib/gcc/x86_64-w64-mingw32/$verMinGw/libgcc_s_seh-1.dll build-cmake-windows/.
	cp /usr/lib/gcc/x86_64-w64-mingw32/$verMinGw/libstdc++-6.dll build-cmake-windows/.
	cp /usr/x86_64-w64-mingw32/lib/libwinpthread-1.dll build-cmake-windows/.
fi
cd build-cmake-windows
cmake -DCMAKE_TOOLCHAIN_FILE=../docker/dependencies/build/CMakeToolchain-win64.cmake ..
make
cd ..

if [ ! -d "build-cmake-raspberry" ]; then
	mkdir build-cmake-raspberry
fi
cd build-cmake-raspberry
cmake -DCMAKE_TOOLCHAIN_FILE=../docker/dependencies/build/CMakeToolchain-rpi.cmake ..
make
cd ..

