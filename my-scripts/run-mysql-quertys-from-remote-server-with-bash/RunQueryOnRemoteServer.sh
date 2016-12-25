#!/bin/bash

echo ">>>>>>>>>>>>>>>>>>>>>>>>> START >>>>>>>>>>>>>>>>>>>>>>"
openLibre=$1
libre="libre"
host=wrote-here.your-mysql-host.com
path="~/repos/my-general-repo/my-scripts/run-mysql-quertys-from-remote-server-with-bash/query-output.csv"

ssh $host << HERE
 sudo su root
 mysql innovid -e "{ WRITE HERE YOUR QUERY }
                   INTO OUTFILE '/tmp/query-output.csv'
                   FIELDS TERMINATED BY ','
                   ENCLOSED BY ''
                   LINES TERMINATED BY '\n';"
HERE

scp $host:/tmp/query-output.csv $path
# cat /Users/moshek/repos/my-scripts-repo/run-mysql-quertys/smart-platform-query/query-output.csv

ssh $host << HERE
 sudo su root
 rm /tmp/query-output.csv
HERE


if [ "$openLibre" == "$libre" ];
then
  nohup /Applications/LibreOffice.app/Contents/MacOS/soffice $path&
fi

echo "<<<<<<<<<<<<<<<<<<<<<<< END <<<<<<<<<<<<<<<<<<<<<<<<<<"
