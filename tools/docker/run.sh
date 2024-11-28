#!/bin/bash

mappings="
-v ${PWD}/..:/root/tutorials
"

docker run \
	--rm \
	$mappings \
	-it "processing-tutorials"

