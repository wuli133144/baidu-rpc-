#!/bin/bash



cd  ./build/

cmake .. && make

if [[ $? != 0 ]]  ;

then
     echo "cmake error!"
 else
     echo "build success!"
fi
