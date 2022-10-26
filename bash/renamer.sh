#!/bin/bash
address=$1
command=$2
controller=0
if [ "$command" = "-c" ] || [ "$command" = "--copy" ]; then
controller=1
fi 
if [ -d $address ]; then 
    date="$(date '+%Y-%m-%d')_"
    if [ $controller == 1 ]; then
        
        for document in $address/*
        do
            name=$(basename $document)
            cp -f $document $address/$date$name
            echo "copy:$name type:${name##*.} -> $date$name"
        done
    fi
    if [ $controller == 0 ]; then
        for document in $address/*
        do
            name=$(basename $document)
            mv $document $address/$date$name
        done
        fi
fi