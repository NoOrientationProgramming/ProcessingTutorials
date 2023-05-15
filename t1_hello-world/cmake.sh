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

