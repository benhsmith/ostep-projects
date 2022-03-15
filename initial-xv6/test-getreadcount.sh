#! /bin/bash

export XV6_PATH=~/ostep/xv6-public

if ! [[ -d $XV6_PATH ]]; then
    echo "$XV6_PATH does not exist."
    echo "Your xv6 code should be in $XV6_PATH directory"
    echo "to enable the automatic tester to work."
    exit 1
fi

../tester/run-tests.sh $*


