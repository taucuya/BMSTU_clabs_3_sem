#!/bin/bash

if [ -z $1 ]; then
    exit 1
fi

../../app.exe < $1 > file_out

if [[ $? -ne 0 ]]; then
	rm file_out
    exit 0
else
	rm file_out
    exit 1
fi
