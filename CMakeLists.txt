project (threads)
cmake_minimum_required(VERSION 2.8)
#set(src_list test_thread_group.cc)
#set(src_list test_thread_group.cc)
set(src_list   test_thread_group1.cc)

include_directories(/usr/local/include )

link_directories(/usr/local/lib /usr/local/)

add_executable(threads ${src_list})

target_link_libraries(threads protobuf pthread z snappy sofa-pbrpc gtest
    gtest_main gflags)
