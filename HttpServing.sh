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

echo "Serving tutorial: $dirTut"

if [ ! -d "$dirTut" ]; then
	echo "Could not serve tutorial. Wrong directory?"
	exit 1
fi

python -m http.server 8000 --directory "$dirTut"

