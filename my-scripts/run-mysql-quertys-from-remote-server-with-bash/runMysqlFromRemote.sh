#!/bin/bash

echo ">>>>>>>>>>>>>>>>>>>>>>>>> START >>>>>>>>>>>>>>>>>>>>>>"
query=$1
host=your.host.com
db=your-db

if [ -z "$query" ]
then
  echo "[ERROR] - can't run empty query :/ "
else
read -d '' sql << EOF
$query
EOF


echo "About to run:"
echo "$sql;"

ssh "$host" << HERE
 sudo su root
 mysql "$db" -t -e "$sql;"
HERE
fi

echo "<<<<<<<<<<<<<<<<<<<<<<< END <<<<<<<<<<<<<<<<<<<<<<<<<<"
