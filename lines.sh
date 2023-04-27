#!/bin/bash

#  This file is part of the DSP-Crowd project
#  https://www.dsp-crowd.com
#
#  Author(s):
#      - Johannes Natter, office@dsp-crowd.com
#
#  File created on 09.03.2023
#
#  Copyright (C) 2023-now Authors and www.dsp-crowd.com

modLineSet()
{
	s="$1"
	category="0"

	if [ "$s" -lt "100" ]; then
		category="0"
		mod=""
	elif [ "$s" -gt "600" ]; then
		category="2"
		mod="\033[91;1m"
	elif [ "$s" -lt "200" ]; then
		category="0"
		mod="\033[93;1m"
	elif [ "$s" -gt "500" ]; then
		category="2"
		mod="\033[93;1m"
	else
		category="1"
		mod="\033[32;1m"
	fi

	return "$category"
}

modGreenSet()
{
	s="$1"

	if [ "$s" -lt "35" ]; then
		mod="\033[91;1m"
	elif [ "$s" -lt "60" ]; then
		mod="\033[93;1m"
	else
		mod="\033[32;1m"
	fi
}

linesPrint()
{
	mod=""

	numLinesSum=0
	numFiles=0
	numSmall=0
	numGreen=0
	numBig=0

	fType="cpp"
	if [ -n "$1" ]; then
		fType="$1"
	fi

	srcs="$(find . -name "*.${fType}" | xargs wc -l | grep -v resources | grep -v total | grep -v build)"
	srcs="$(echo "$srcs" | sort -n | tr -s ' ' | sed 's:^[ \t]*::g' | sed 's: :|:g')"
	#echo "$srcs" | hexdump -n 64 -C
	#echo "$srcs" | head -n 10

	echo
	echo "----------------------------------"

	for s in $srcs; do

		#echo "~${s}~"

		numLines="$(echo "$s" | cut -d '|' -f 1)"
		f="$(echo "$s" | cut -d '|' -f 2)"
		#echo "~${f}~"
		bName="$(basename $f)"
		dName="$(dirname $f)"
		#f="${f:2}"

		modLineSet "$numLines"
		category="$?"
		if [ "$category" == "0" ]; then
			numSmall=$((numSmall + 1))
		elif [ "$category" == "1" ]; then
			numGreen=$((numGreen + 1))
		else
			numBig=$((numBig + 1))
		fi

		lic="-"

		found="$(grep "free of charge" "$f")"
		if [ -n "$found" ]; then
			lic="MIT"
		fi

		found="$(grep "version 3 of the License" "$f")"
		if [ -n "$found" ]; then
			lic="GPLv3"
		fi

		printf "$mod%25s\033[0m   %-8s%-40s%s\n" "$numLines" "$lic" "$bName" "$dName"

		numLinesSum=$((numLinesSum + numLines))
		numFiles=$((numFiles + 1))
	done

	echo "----------------------------------"
	printf "\033[96;1mSum%22s\033[0m\n\n" "$numLinesSum"

	echo "----------------------------------"
	printf "Files%20s\n" "$numFiles"

	printf "\n"

	c1=$(($numSmall * 100 / $numFiles))
	printf "Small%20s (%d%%\033[0m)\n" "$numSmall" "$c1"

	c2=$(($numGreen * 100 / $numFiles))
	modGreenSet "$c2"
	printf "Green%20s ($mod%d%%\033[0m)\n" "$numGreen" "$c2"

	c3=$((100 - $c1 - $c2))
	printf "Big%22s (%d%%\033[0m)\n" "$numBig" "$c3"

	printf "\n"

	echo "----------------------------------"
	d=$(($numLinesSum / $numFiles))
	modLineSet "$d"
	printf "Avg. lines$mod%15s\033[0m\n\n" "$d"

	echo "----------------------------------"
	g=$(git slog 2> /dev/null | wc -l)
	printf "Commits%18s\n\n" "$g"
}

linesPrint $* | less -R +G

