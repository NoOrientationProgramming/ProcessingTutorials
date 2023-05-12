#!/bin/bash

if [ ! -d "build-ubuntu" ]; then
	meson setup build-ubuntu
fi
ninja -C build-ubuntu

if [ ! -d "build-windows" ]; then
	meson setup --cross-file ../docker/dependencies/build/crosscompile-win64.txt build-windows
fi
ninja -C build-windows

if [ ! -d "build-raspberry" ]; then
	meson setup --cross-file ../docker/dependencies/build/crosscompile-rpi.txt build-raspberry
fi
ninja -C build-raspberry

