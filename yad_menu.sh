#!/bin/bash
     
echo $0
printf "< Choose menu >"
#sudo apt install yad
   
alert=$(yad --width 300 --title "Choose menu?" --button="Movie payment:1" --button="Movie you Watched:2") result=$?
echo $result

if ((result==1));then
	echo "111"     
fi

if ((result==2));then
	echo "~ Movie you Watched ~"
	/home/pi/mp2/CRUD_function.c



fi
 
exit 0
