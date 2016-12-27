#!/bin/bash

echo ">>>>>>>>>>>>>>>>>>>>>>>>> START >>>>>>>>>>>>>>>>>>>>>>"
openLibre=$1
libre="libre"
host=wrote-here.your-mysql-host.com
db=your-db
path="~/repos/my-general-repo/my-scripts/run-mysql-quertys-from-remote-server-with-bash/query-output.csv"

ssh "$host" << HERE
 sudo su root
 mysql "$db" -e "{ WRITE HERE YOUR QUERY }
                   INTO OUTFILE '/tmp/query-output.csv'
                   FIELDS TERMINATED BY ','
                   ENCLOSED BY ''
                   LINES TERMINATED BY '\n';"
HERE

scp "$host":/tmp/query-output.csv $path

ssh "$host" << HERE
 sudo su root
 rm /tmp/query-output.csv
HERE


if [ "$openLibre" == "$libre" ];
then
  nohup /Applications/LibreOffice.app/Contents/MacOS/soffice $path&
fi

echo "<<<<<<<<<<<<<<<<<<<<<<< END <<<<<<<<<<<<<<<<<<<<<<<<<<"
