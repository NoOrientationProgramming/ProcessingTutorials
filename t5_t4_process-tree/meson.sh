#!/bin/bash

if [ ! -d "build-meson-ubuntu" ]; then
	meson setup build-meson-ubuntu
fi
ninja -C build-meson-ubuntu

if [ ! -d "build-meson-windows" ]; then
	meson setup --cross-file ../docker/dependencies/build/crosscompile-win64.txt build-meson-windows
fi
ninja -C build-meson-windows

if [ ! -d "build-meson-raspberry" ]; then
	meson setup --cross-file ../docker/dependencies/build/crosscompile-rpi.txt build-meson-raspberry
fi
ninja -C build-meson-raspberry

