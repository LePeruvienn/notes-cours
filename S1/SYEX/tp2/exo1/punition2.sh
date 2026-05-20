#!/bin/sh
#
#usage: punition1.sh n m word

if [ $# -ne 3 ] ; then
    echo >&2 "usage: $0 <int> <int> <str>"
    exit 1
fi

n="$1"
m="$2"
word="$3"

i=0
# lt = less than (moins que), <=
while [ $i -lt "$n" ] ; do
    j=0 
    str=
    while [ $j -lt "$m" ]; do
        str="$str$word "
        # incrémente j
        j=$((j+1))
    done
    echo "$str"
    i=$((i+1))
done

