#!/bin/bash
#Head

echo 'welcome to script, please follow instructions'
if [ "$1" = "?" ]
	then
		echo 'Write name of file and size {ERROR 1}'
	exit
elif [ "$#" = 0 ]
	then
		echo 'write name of file and size {ERROR 2}'
	exit
elif [ "$#" = 2 ]
	then
		name="$1"
		size="$2"
	else
		echo 'Write name of file and size {ERROR 3}'
	exit
fi

#Body

while [ $(du -c $name*|tail -n 1|cut -f1) -gt $size ]
do
	rm -f $(du -s $name*|sort -h|tail -n 1)
done
