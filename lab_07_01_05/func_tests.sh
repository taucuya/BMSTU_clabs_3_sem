#!/bin/bash

if [ ! -f "./app.exe" ]; then
    echo "Build app.exe first"
    exit 1
fi

# Negatives
negs_args=$(find ./func_tests -maxdepth 1 -name "neg_*_args*" | sort)
#echo "negs_args: ${negs_args}"

count=0
for n in $negs_args; do
    count=$((count + 1))
    neg_in="$(echo "$n" | sed "s/args/in/g")"
    #echo "${neg_in}"
    
    ./app.exe $n
    rc=$(echo $?)
    
    if [ "$rc" != "0" ]; then
        #count=$((count + 1))
        echo "NEGATIVE ${count} passed"
    else
        echo "NEGATIVE ${count} failed"
    fi
done

echo -n -e "\n\n\n"

# Positives
touch /tmp/buffer
buf=/tmp/buffer

pos_args=$(find ./func_tests -maxdepth 1 -name "pos_*_args*" | sort)
#echo "pos_args: ${pos_args}"

count=0
for p in $pos_args; do
    count=$((count + 1))
    pos_in="$(echo "$p" | sed "s/args/in/g")"
    pos_out="$(echo "$p" | sed "s/args/out/g")"
    #echo "${pos_in} -> ${pos_out}"
    
    ./app.exe $p

   # cat $buf
   # echo -n -e "\n\n\n"
   # cat $pos_out
    if cmp -s $pos_out $buf; then
        count=$((count + 1))
        echo "POSITIVE ${count} failed"
    else
        echo "POSITIVE ${count} passed"
    fi
done
