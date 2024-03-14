#!/bin/bash

file_1=$1
file_2=$2


if cmp -s file_1 file_2; then
  exit 1
else
  exit 0
fi

