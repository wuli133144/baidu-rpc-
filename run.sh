#!/bin/bash



./clean.sh && ./cmake-scripts.sh

if [[ $? == 0 ]] ;
 then
      echo "build success!"
 else
     echo "cmake error!"
fi


exec ./build/threads
