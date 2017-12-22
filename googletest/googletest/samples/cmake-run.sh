#!/bin/bash


echo "welcome to cmake world"

#cd ./build/ && cmake .. && make
# exit 0

function cmake(){

cd ./build/ && cmake .. && make
 #cd ./build/ && cmake .. && make
return

}

#cmake()

cp ./build/gtest_unit1 ./




