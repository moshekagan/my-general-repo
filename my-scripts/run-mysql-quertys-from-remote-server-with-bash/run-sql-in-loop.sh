#!/bin/bash
echo ">>>>>>>>>>>>>>>>>>>>>>>>> START >>>>>>>>>>>>>>>>>>>>>>"

now=$(date +"%H:%M:%S:%3N")
echo "Start time: $now"

for (( c=1; ; c++ ))
do
  now=$(date +"%H:%M:%S:%3N")
  echo "$c. $now"
  # mysql innovid -t < "/tmp/serializer-query-2.sql"
done
echo "<<<<<<<<<<<<<<<<<<<<<<<<<< END <<<<<<<<<<<<<<<<<<<<<<<"
