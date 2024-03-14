#!/bin/bash

if [ -z $1 -o -z $2 ]; then
    exit 1
fi

touch file_out
../../app.exe < $1 > file_out
./comparator_num.sh file_out $2


if [[ $? =~ 0 ]]; then
	rm file_out
    exit 0
else
	rm file_out
    exit 1
fi
