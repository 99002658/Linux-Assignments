#!/bin/bash
#Abhishek
input=Input2.csv
OLDIFS=$IFS
IFS=','
[ ! -f $input ] && { echo "$INPUT file not found"; exit 99; }
sed 1d $input | while read -r Name email repolink
do
	echo "Name : $Name"
	echo "Email ID : $email"
	echo "Repo Link : $repolink"
      	git clone $repolink
	if [ $? -eq 0 ];then
      		folder=$(basename  "$repolink"|cut -d . -f1)
		echo $folder
		chmod 777 $folder
		mv  /home/genesis58/Desktop/ShellScript/Results.csv /home/genesis58/Desktop/ShellScript/$folder/
		cd $folder
		make
		if [ $? -eq 0 ]; then
			touch val.txt
			touch cpp.txt
			chmod 777 val.txt
			chmod 777 cpp.txt
			cppcheck ./all.out 2> cpp.txt
			if [ $? -eq 0 ]; then
				valgrind ./all.out 2> val.txt
				cp1=$(grep -wc "error" cpp.txt)
				va1=$( tail -n 1 val.txt )
				echo $cp1
				echo $va1
				if [ $? -eq 0 ]; then
					printf '%s' $Name,$email,$repolink,'Success','Success',$cp1,$va1 | paste -sd ',' >> Results.csv
				fi
			fi
		fi
		else
			printf '%s' $name,$email,$repolink,'NotSuccess','1','1','1' | paste -sd ','>>Results.csv
	fi
	echo
done < $input
IFS=$OLDIFS
