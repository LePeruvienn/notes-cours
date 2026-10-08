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
while [ $i -lt "$m" ]; do
    str="$str$word "
    # incrémente j
    i=$((i+1))
done
# on donne notre ligne à punition1, qui s'occupera de la répéter n fois
sh punition1.sh "$n" "$str"

