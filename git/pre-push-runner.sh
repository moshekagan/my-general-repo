#!/bin/bash

gcp_sdk_path='/Users/kaganmoshe/workspace/google-cloud-sdk'
illist_path='/Users/kaganmoshe/repos/illist'

cd $illist_path/illistsite

echo About to run: python $illist_path/illistsite/test_runner.py $gcp_sdk_path/platform/google_appengine --test-path=tests

python $illist_path/illistsite/test_runner.py $gcp_sdk_path/platform/google_appengine --test-path=tests
test_result=$?


if [ "$test_result" = 0 ]; then
    printf -- '\033[32m SUCCESS: Tests passed successfully :) \033[0m\n';
    exit 0
else
    printf -- '\033[31m ERROR: Some tests failed :( \033[0m\n';
    exit 1
fi
