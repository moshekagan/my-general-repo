import os
import subprocess

gcp_sdk_path='/Users/kaganmoshe/workspace/google-cloud-sdk'
illist_path='/Users/kaganmoshe/repos/illist'

tests_running_directory = illist_path + '/illistsite'
run_tests_command_args = ['python', illist_path + '/illistsite/test_runner.py', gcp_sdk_path + '/platform/google_appengine', '--test-path=tests/unit_tests']

print 'Running tests...'
os.chdir(tests_running_directory)
if subprocess.call(run_tests_command_args) == 0:
    print 'SUCCSS: tests passed succssfully'
    exit(0)
else:
    print 'ERROR: some tests failed :('
    exit(1)
