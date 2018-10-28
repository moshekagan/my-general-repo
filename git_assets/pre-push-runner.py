import subprocess

gcp_sdk_path='/Users/kaganmoshe/workspace/google-cloud-sdk'
illist_path='/Users/kaganmoshe/repos/illist'



print 'Running tests...'
if subprocess.call(['python', illist_path + '/illistsite/test_runner.py', gcp_sdk_path + '/platform/google_appengine', '--test-path=tests/unit_tests']) == 0:
    print 'SUCCSS: tests passed succssfully'
    exit(0)
else:
    print 'ERROR: some tests failed :('
    exit(1)
