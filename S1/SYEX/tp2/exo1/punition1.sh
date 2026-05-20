#!/bin/sh
#
#usage: punition1.sh n word

if [ $# -ne 2 ] ; then
    echo >&2 "usage: $0 <int> <str>"
    exit 1
fi

n="$1"
word="$2"

i=0
while [ $i -lt "$n" ] ; do
    echo "$word"
    i=$((i+1))
done

