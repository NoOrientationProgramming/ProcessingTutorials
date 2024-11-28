#!/bin/bash

echo "Docker shell"

while test $# -gt 0
do
    $1
    shift
done

exit 0
