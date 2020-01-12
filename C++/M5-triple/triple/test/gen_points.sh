#! /bin/bash

cat /dev/null > tmc_available_points.txt

ex=1
while read p; do
    if [[ "$p" =~ "<testsuite " ]];
    then
        ((ex++))
    fi
    if [[ "$p" =~ "<testcase " ]];
    then
        value=${p#*=}
        set -- $value

        name=$1
        shift
        bar=$@
        echo "[test] [$name] 5.$ex" | tr -d '"' >> tmc_available_points.txt
    fi
done <tmc_test_results.xml
