#!/bin/bash

# Скрипт должен находиться в корне папки с ЛР (Рядом с makefile)
# Данные расположены в папке ./func_tests/data
# Запуск ./func_test.sh

# Check dir's existion
DATA_DIR="./func_tests/data"
if ! [ -d "$DATA_DIR" ]; then
    echo "[err]: Data directory not found"
    exit -1
fi


# Handle pos cases
pos_in=$(find "$DATA_DIR" -type f -name "pos*in*" | sort)
pos_total=$(wc -l <<< "$pos_in")
pos_total=$(sed "s/ //g" <<< "$pos_total")

for in_file in $pos_in; do
    pos_out="$(echo "$in_file" | sed "s/in/out/g")"
    pos_args="$(echo "$in_file" | sed "s/in/args/g")"
    num=$(echo "$in_file" | grep -o -E "[0-9]+")

    # Run test case
    buffer="${DATA_DIR}/buffer.txt"
    touch $buffer

    # Test output
    args=$(cat $pos_args)
    ./app.exe $args > ./func_tests/data/buffer.txt

    # Test mem
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="./func_tests/data/memlog.txt" -v ./app.exe $args > $buffer
    memrep=$(grep "[1-9] errors" ./func_tests/data/memlog.txt)


    if cmp -s $pos_out $buffer; then
        echo "Positive test ${num} : PASS"
        if [ $memrep == ""]; then
            echo "Memory : PASS"
        fi
    else
        echo "Positive test ${num} : FAIL"
    fi
done

echo -n -e "\n\n\n"

# Handle neg cases
neg_in=$(find "$DATA_DIR" -type f -name "neg*in*" | sort)
neg_total=$(wc -l <<< "$neg_in")
neg_total=$(sed "s/ //g" <<< "$neg_total")

for in_file in $neg_in; do
    neg_out="$(echo "$in_file" | sed "s/in/out/g")"
    neg_args="$(echo "$in_file" | sed "s/in/args/g")"
    num=$(echo "$in_file" | grep -o -E "[0-9]+")

    # Run test case
    buffer="${DATA_DIR}/buffer.txt"
    touch $buffer

    # Test output
    args=$(cat $neg_args)
    ./app.exe $args > ./func_tests/data/buffer.txt

    # Test mem
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="./func_tests/data/memlog.txt" -v ./app.exe $args > $buffer
    memrep=$(grep "[1-9] errors" ./func_tests/data/memlog.txt)
    rc="$?"

    if [ $rc != "0" ]; then
        echo "Negative test ${num} : PASS"
        if [ $memrep == ""]; then
            echo "Memory : PASS"
        fi
    else
        echo "Negative test ${num} : FAIL"
    fi
done
