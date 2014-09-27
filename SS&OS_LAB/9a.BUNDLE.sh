#!/bin/bash
echo "#to unbundle,bash this file"
for i
do
echo "echo $i 1>&2"
echo "cat >$i << 'End of $i'"
cat $i
echo "End of $i"
done
