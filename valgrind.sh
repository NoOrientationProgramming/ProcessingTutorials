#!/bin/bash

dirTut="t01_tcp-echo-server"

if [ ! -z "$1" ]; then
	inUser="$1"

	echo "User input: $inUser"

	if [ -d "$inUser" ]; then
		dirTut="$inUser"
	else
		dirTut="$(ls -1 | grep "$inUser" | sort | head -n 1)"
	fi
fi

tool="app"
argsDefault=()
dBuildDefault="build-meson-ubuntu"

dHere="$(pwd)"
dTarget="$dirTut/$dBuildDefault"

dRelHereToTarget="$(realpath --relative-to="$dHere" "$dTarget")"

cd "${dRelHereToTarget}" && \
ninja && \

valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-fds=yes \
	--track-origins=yes \
./$tool \
	"${argsDefault[@]}" \
	"$@"

