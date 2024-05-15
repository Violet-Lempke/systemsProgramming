#!/bin/bash
# A more specialized reminder service
set `date`
date=$1
time=$4
##time=$2
echo "It is $4 on $1day"
if test ! $date = Sun || test ! $date = Sat
then
	case $time in 
 		05:5*)
			if test ${time:4:1} -gt 4
			then
			echo "It is about 7 a.m., get up"
		fi
		;;
	
 		06:0*)
			if test ${time:4:1} -lt 6
			then
				echo "It is about 7 a.m., get up"
			fi
			;;
  
		06:5*)
			if test ${time:4:1} -gt 4
			then
				echo "It is about 7 a.m., have breakfast"
			fi
			;;
		07:0*)
			if test ${time:4:1} -lt 6
			then
				echo "It is about 7 a.m., have breakfast"
			fi
			;;

		07:5*)
			if test ${time:4:1} -gt 4
			then
				echo "It is about 8 a.m., start the first class"
			fi
			;;

		08:0*)
			if test ${time:4:1} -lt 6
			then
				echo "It is about 8 a.m., start the first class"
			fi
			;;

		21:5*)
			if test ${time:4:1} -gt 4
			then
				echo "It is about 10 p.m., finish your homework"
			fi
			;;

		22:0*)
			if test ${time:4:1} -lt 6
			then
				echo "It is about 10 p.m., finish your homework"
			fi
			;;
	esac
else
	echo "It's the weekend, finish up any leftover work, study, and take some time for yourself"
fi
