#!/bin/bash

print_usage()
{
  printf "Usage: ./func_tests.sh [-b] -- rebuild release main.c version\n [-s] -- use string comparator\n [-n] -- use numbers comparator [-v] -- verbose mode\n"
}

get_stats()
{
  echo " "
  echo "Statistics: "
  echo "Positive tests: ${pos_ok_count} out of ${pos_test_amount}"
  echo "Negative tests: ${neg_ok_count} out of ${neg_test_amount}"
}



#########################################
# Prepare JSON for fancy Golang output. #
#########################################
json=func_tests/data/.report.json
rm -rf $json
touch $json
echo "[" >> $json



#######################################################
# Define scripts behaviour based on the CLI arguments #
####################################################### 
flag_rebuild=""
flag_strcomp=""
flag_numcomp=""
flag_verbose=""
flag_correct_dir=""

# Check wether we're in a root or in scripts/
if [ "$(pwd)" != "/*/scripts" ]; then
  cd ./func_tests/scripts
  flag_correct_dir="false"
fi

while getopts "nbsv" flag; do
  case "${flag}" in
    b) flag_rebuild="true" ;;
    s) flag_strcomp="-s" ;;
    n) flag_numcomp="-n" ;;
    v) flag_verbose="true" ;;

    *) print_usage
        exit 1
        ;;
  esac
done



##################################
# Handle incorrect CLI arguments #
##################################
if [ -n "$flag_strcomp" ] && [ -n "$flag_numcomp" ]; then
  printf "[ERR] - comparator's behaviour is undefined.\n (!) Hint don't use [-s] 
&& [-n] together\n"
  exit 1
elif [ -n "$flag_strcomp" ] && [ -z "$flag_numcomp" ]; then
  flag="-s"
elif [ -z "$flag_strcomp" ] && [ -n "$flag_numcomp" ]; then
  flag="-n"
else
  flag=""
fi



#############################
# Rebuild project if needed #
#############################
if [ -n "$flag_rebuild" ]; then
  cd ../..
  ./build_release.sh
  chmod +x main.exe
  cd func_tests/scripts
fi



#########################
# Handle positive cases #
#########################
pos_ok_count=0
poses=$(find ../data -type f -name "pos*in*" | sort)
pos_test_amount=$(wc -l <<< "$poses")
pos_test_amount=$(sed "s/ //g" <<< "$pos_test_amount")

for input_file in $poses; do
  output_file="$(echo "$input_file" | sed "s/in/out/g")"
  args_file="$(echo "$input_file" | sed "s/in/args/g")"

  ./pos_case.sh "$input_file" "$output_file" "$flag" "$flag_verbose" "$args_file"
  return_code="$?"
  if [ "$return_code" == "0" ]; then
    pos_ok_count=$((pos_ok_count + 1))
  fi
done
echo " "



#########################
# Handle negative cases #
#########################
neg_ok_count=0
negs=$(find ../data -type f -name "neg*in*" | sort)
neg_test_amount=$(wc -l <<< "$negs")

neg_test_amount=$(sed "s/ //g" <<< "$neg_test_amount")

for input_file in $negs; do
  output_file="$(echo "$input_file" | sed "s/in/out/g")"
  args_file="$(echo "$input_file" | sed "s/in/args/g")"


  ./neg_case.sh "$input_file" "$output_file" "$flag" "$flag_verbose" "$args_file"
  return_code="$?"
  if [ "$return_code" == "0" ]; then
    neg_ok_count=$((neg_ok_count + 1))
  fi
done



###################
# Stats if needed #
###################
if [ -n "$flag_verbose" ]; then
  get_stats
fi

if [ "$pos_test_amount" == "$pos_ok_count" ] && [ "$neg_test_amount" == "$neg_ok_count" ]; then
  exit 0
else
  exit 1
fi

if [ -n "$flag_correct_dir" ]; then
  cd ../..
fi
