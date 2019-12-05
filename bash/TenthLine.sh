#!/bin/bash

cnt=0
TARGET=10

while read line
do
        cnt=$[$cnt+1]
        if [ $cnt -eq $TARGET ]; then
                echo $line
                break
        fi
done < ./file.txt