#!/bin/bash


p_t=($(ls ../data | grep "^pos_")) 
ln=${#p_t[@]}
cnt=1
er=0
for ((i = 0; i<$ln; i=i+2))
do
    ./pos_case.sh "../data/${p_t[$i]}" "../data/${p_t[$i+1]}"

    if [[ $? =~ 0  ]]; then
        echo you passed positive test number $cnt
    else
        echo you didnt pass positive test number $cnt
        er=$(($er+1))
    fi
    
    cnt=$(($cnt+1))
done
n_t=($(ls ../data | grep "^neg_[0-9][0-9]_in.txt$")) 
ln=${#n_t[@]}
i=0
cnt=1
for ((i = 0; i<$ln; i++))
do	
    ./neg_case.sh "../data/${n_t[i]}"
    if [[ $? =~ 0  ]]; then
        echo you passed negative test number $cnt
    else
        echo you didnt pass negative test number $cnt
        er=$(($er+1))

    fi
    
    cnt=$(($cnt+1))
done
if [[ $er =~ 0 ]]; then
    echo you passed all tests
    exit 0
else
    echo you failed some tests
    exit $er
fi
