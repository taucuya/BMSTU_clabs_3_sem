#!/bin/bash

[[ $# -ne 2 ]] && echo "Invalid launch. Specify amount of files: ./gen_files.sh 'pos_amount' 'neg_amount'"


for (( i=1; i<=$1; i++ )) do
    num=$(printf "%02d" $i)
    pos_in_fname="./func_tests/data/pos_${num}_in.txt"
    pos_out_fname="./func_tests/data/pos_${num}_out.txt"

    touch $pos_in_fname
    touch $pos_out_fname
done

for (( i=1; i<=$2; i++ )) do
    num=$(printf "%02d" $i)
    neg_in_fname="./func_tests/data/neg_${num}_in.txt"
    neg_out_fname="./func_tests/data/neg_${num}_out.txt"

    touch $neg_in_fname
    touch $neg_out_fname
done
