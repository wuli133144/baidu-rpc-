project(gtest_unit1)

cmake_minimum_required(VERSION 2.8)

set(src_list  sample1_unittest.cc sample1.h sample1.cc)

include_directories(/usr/include/ /usr/include/gtest /usr/include/gtest/internal)

link_directories(/usr/lib ../ ./  /usr/lib64 /usr/local/lib)

add_executable(gtest_unit1  ${src_list} )

target_link_libraries(gtest_unit1  gtest pthread gtest_main )

