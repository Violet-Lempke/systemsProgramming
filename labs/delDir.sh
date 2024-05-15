##Script to delete a directory interactively
directoryName=$1
if test -f $directoryName
	then
		echo "\"$directoryName\" is a file"
		exit 0
	elif test ! -d $directoryName
		then
			echo "cannot access $directoryName: No such file or directory"
			exit 0
fi
echo "Do you want to delete \"$directoryName\"?"
echo "y/n"
read choice

if test $choice = y
	then
		rmdir $directoryName
		echo "deleted \"$directoryName\""
	else
		echo "\"$directoryName\" not deleted"
fi
