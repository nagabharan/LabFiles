#!/bin/bash
rev=""
if [ $# -eq 0 ];
then
	echo "Usage error"
	exit
fi
echo "Total no of args: $#"
echo "Args are: $*"
echo "Args in reverse: "
for i in $*
do
	rev=$i" "$rev
done
echo $rev
