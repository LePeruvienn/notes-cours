# usage: s36str a b c  => s36str a a b b c c
# usage: s36str k1 s1 k2 s2 k3 s3
# affiche les chaines s(i) en fonction de l'ordre
# des cles k(i). Les cles sont comparees de facon
# lexicographique.

s36str() {
  if [ $# -eq 3 ]; then
    s36str "$1" "$1" "$2" "$2" "$3" "$3"
    return 0
  fi
  if [ ! "$1" \> "$3" -a ! "$3" \> "$5" ]; then
    echo $2
    echo $4
    echo $6
  elif [ ! "$1" \> "$5" -a ! "$5" \> "$3" ]; then
    echo $2
    echo $6
    echo $4
  elif [ ! "$3" \> "$1" -a ! "$1" \> "$5" ]; then
    echo $4
    echo $2
    echo $6
  elif [ ! "$3" \> "$5" -a ! "$5" \> "$1" ]; then
    echo $4
    echo $6
    echo $2
  elif [ ! "$5" \> "$1" -a ! "$1" \> "$3" ]; then
    echo $6
    echo $2
    echo $4
  else
    echo $6
    echo $4
    echo $2
  fi
}

s36int() {
  if [ $# -eq 3 ]; then
    s36int $1 $1 $2 $2 $3 $3
    return 0
  fi
  if [ ! $1 -gt $3 -a ! $3 -gt $5 ]; then
    echo $2
    echo $4
    echo $6
  elif [ ! $1 -gt $5 -a ! $5 -gt $5 ]; then
    echo $2
    echo $6
    echo $4
  elif [ ! $3 -gt $1 -a ! $1 -gt $5 ]; then
    echo $4
    echo $2
    echo $6
  elif [ ! $3 -gt $5 -a ! $5 -gt $1 ]; then
    echo $4
    echo $6
    echo $2
  elif [ ! $5 -gt $1 -a ! $1 -gt $3 ]; then
    echo $6
    echo $2
    echo $4
  else
    echo $6
    echo $4
    echo $2
  fi
}

# usage: isInt str
# returns 0 if str represents an integer, 1 otherwise

isInt() {
  local n="$1"
  local m=$(echo "$n" | sed -r -e '1s/[+-]?[0-9]+//')
  test -z "$m"
}
