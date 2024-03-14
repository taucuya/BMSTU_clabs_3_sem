#!/bin/bash

# Works when main.exe file is already created in the root folder

print_verbose()
{
  printf "%s\n" "$1"
}

input_data=$1
output_data=$2
args=$5
touch ../data/buffer_out.txt
buffer="../data/buffer_out.txt"
exe_file="../../main.exe"

if [ -z "$output_file" ]; then
  $exe_file "$args" > "$buffer"
  return_code_exe="$?"
  logger=../../logger.sh
  if [ "$return_code_exe" != "0" ]; then
    pass="OK"
  else
    pass="FAIL"
  fi
  $logger "$input_data" "$return_code_exe" "$pass" "neg"
  if [ "$return_code_exe" != 0 ]; then
    exit 0
  fi

  else
      if [ "$3" == "-s" ]; then
        comparator="../.././str_comparator.sh"
      elif [ "$3" == "-n" ]; then
        comparator="../.././num_comparator.sh"
      else
        comparator="../.././comparator.sh"
      fi

      if [ -n "$4" ]; then
        flag_verbose="-v"
      else
        flag_verbose=""
      fi

      test_num=$(echo "$input_data" | grep -o -E "[0-9]+")
      touch ../data/buffer_out.txt
      buffer="../data/buffer_out.txt"
      exe_file="../../main.exe"

      $exe_file "$input_data" > "$buffer"
      return_code_exe="$?"

      $comparator "$output_data" "$buffer" "$flag_verbose"
      return_code_diff="$?"

      logger=../../logger.sh
      if [ "$return_code_exe" != "0" ]; then
        pass="OK"
      else
        pass="FAIL"
      fi
      #$logger "$input_data" "$return_code_exe" "$pass" "neg"
      
      pass=""
      if [[ "$return_code_exe" != "0" ]]; then
        pass="OK"
        if [ "$return_code_diff" == "0" ]; then
          if [ -n "$flag_verbose" ]; then
            print_verbose "Negative test ${test_num} : PASS"
            pass="OK"
          fi
          #exit 0
        else
          if [ -n "$flag_verbose" ]; then
            print_verbose "Negative test ${test_num} : FAIL (Different output data)"
          fi
          #exit 1
        fi
      else
      pass="FAIL"
        if [ -n "$flag_verbose" ]; then
          print_verbose "Negative test ${test_num} : FAIL (Zero return code)"
        fi
        #exit 1
      fi
fi
