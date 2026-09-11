#!/bin/bash

word=
m=
n=



default="Je ne bavarde pas en cours!"

# gt = greater than, plus grand que, >=
if [ $# -gt 3 ]; then
    echo >&2 "usage: $0 <int> <int> <str>"
    echo >&2 "or $0 <int> <str>"
    echo >&2 "or $0 <str>"
    echo >&2 "or $0"
fi

# dans le cas où on a 3 arguments, et ainsi de suite...
# on déclare en avance les arguments et après on les utilise
# sur punition3.
# une autre façon de faire serait d'appeler directement punition3 avec
# les arguments (punition3 "$1" "$2" "$3", punition3 10 "$1" "$2", ...)
if [ $# -eq 3 ]
then
  word=$3
  m=$2
  n=$1
elif [ $# -eq 2 ]
then
  word=$2
  m=$1
  n=10
elif [ $# -eq 1 ]
then
  word=$1
  m=3
  n=10
else
  word=$default
  m=3
  n=10
fi

sh punition3.sh "$n" "$m" "$word"
