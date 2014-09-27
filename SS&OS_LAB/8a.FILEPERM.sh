if [ $# -ne 2 ];
then
	echo "Error"
	exit
fi

perm1=`ls -l $1 | cut -c 1-10`
perm2=`ls -l $2 | cut -c 1-10`
u1=`ls -l $1 | cut -c 2-4`
u2=`ls -l $2 | cut -c 2-4`
g1=`ls -l $1 | cut -c 5-7`
g2=`ls -l $2 | cut -c 5-7`
o1=`ls -l $1 | cut -c 8-10`
o2=`ls -l $2 | cut -c 8-10`
r1=`ls -l $1 | cut -c 2,5,8`
r2=`ls -l $2 | cut -c 2,5,8`
w1=`ls -l $1 | cut -c 3,6,9`
w2=`ls -l $2 | cut -c 3,6,9`
x1=`ls -l $1 | cut -c 4,7,10`
x2=`ls -l $2 | cut -c 4,7,10`
if [ $perm1 = $perm2 ];
then
	echo "Same file permissions"
	echo "Permissions of $1 and $2 are $perm1"
else
	echo "Different file permissions"
	if [ $u1 = $u2 ];
	then
		echo "Same user permissions"
		echo "File 1 $1 and $2: $u1"
	else
		echo "Different user permissions"
		echo "File 1 $1 : $u1"
		echo "File 1 $2 : $u2"
	fi
	if [ $g1 = $g2 ];
	then
		echo "Same group permissions"
		echo "File 1 $1 and $2: $g1"
	else
		echo "Different group permissions"
		echo "File 1 $1 : $g1"
		echo "File 2 $2 : $g2"
	fi
	if [ $o1 = $o2 ];	
	then
		echo "Same user permissions"
		echo "File 1 $1 and $2: $o1"
	else
		echo "Different world permissions"
		echo "File 1 $1 : $o1"
		echo "File 2 $2 : $o2"
	fi	
	if [ $r1 = $r2 ];
	then
		echo "Same read permissions"
		echo "File 1 $1 and $2: $r1"
	else
		echo "Different read permissions"
		echo "File 1 $1 : $r1"
		echo "File 1 $2 : $r2"
	fi
	if [ $w1 = $w2 ];
	then
		echo "Same group permissions"
		echo "File 1 $1 and $2: $w1"
	else
		echo "Different write permissions"
		echo "File 1 $1 : $w1"
		echo "File 2 $2 : $w2"
	fi
	if [ $x1 = $x2 ];	
	then
		echo "Same execute permissions"
		echo "File 1 $1 and $2: $x1"
	else
		echo "Different execute permissions"
		echo "File 1 $1 : $x1"
		echo "File 2 $2 : $x2"
	fi
fi
