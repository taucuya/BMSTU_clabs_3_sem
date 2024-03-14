#!/bin/bash

if [ -n "$3" ]; then
  flag_verbose="-v"
else
  flag_verbose=""
fi

print_verbose()
{
  # print_debugging "text to echo" "file to cat"
  if [ -n "$flag_verbose" ] && [ -z "$2" ]; then
    echo "$1"
  elif [ -n "$flag_verbose" ] && [ -n "$2" ]; then
    printf "%s\n" "$1"
    cat "$2"
  fi
}

string="Result:"

file_1=$1
file_2=$2

touch /tmp/buffer_1
touch /tmp/buffer_2


flag=false
while read -r line
do

	if [ "$flag" = "true" ]; then
		echo "$line" >> /tmp/buffer_1
	else
		for word in $line; do
			if [[ $word =~ $string ]]; then
				(sed -n -e "s/^.*\(Result:.*\)/\1/p" <<< "$line") > /tmp/buffer_1
				flag=true
				break
			fi
		done
	fi
done < "$file_1"


flag=false
while read -r line
do

	if [ "$flag" = "true" ]; then
		echo "$line" >> /tmp/buffer_2
	else
		for word in $line; do
			if [[ $word =~ $string ]]; then
				(sed -n -e "s/^.*\(Result:.*\)/\1/p" <<< "$line") > /tmp/buffer_2
				flag=true
				break
			fi
		done
	fi
done < "$file_2"

if cmp -s /tmp/buffer_1 /tmp/buffer_2; then
  rm /tmp/buffer_1 /tmp/buffer_2
  exit 0
else
  rm /tmp/buffer_1 /tmp/buffer_2
  exit 1
fi

