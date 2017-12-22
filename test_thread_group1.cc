


#include <gtest/gtest.h>
#include <sofa/pbrpc/thread_group.h>
#include<gflags/gflags.h>
#include <iostream>

#include <sofa/pbrpc/closure.h>

DEFINE_string(ipaddr,"localhost:127.0.0.1","wuyujie");
DEFINE_string(ipaddr1,"localhost:127.0.0.1","wuyujie");
DEFINE_string(ipaddr2,"localhost:127.0.0.1","wuyujie");

DEFINE_int32(num,4,"thread_num");




TEST(wuyjie,define){

  
    sofa::pbrpc::ThreadGroup *group=new sofa::pbrpc::ThreadGroup(FLAGS_num);

    EXPECT_EQ(4,group->thread_num());
    EXPECT_EQ(group->thread_num(),6);
    EXPECT_EQ(group->thread_num(),7);
   
}




static void callback(void ){
   
    std::cout<<"callback is running\n "<<std::endl;

}



int main(int argc,char **argv){
    


    

    gflags::ParseCommandLineFlags(&argc,&argv,true); //参数解析

    ::testing::InitGoogleTest(&argc,argv);  

    printf("%s",FLAGS_ipaddr.c_str());  //输出
    


    
    sofa::pbrpc::ThreadGroup *group=new sofa::pbrpc::ThreadGroup(FLAGS_num);

    group->dispatch(sofa::pbrpc::NewClosure(&callback));



    return RUN_ALL_TESTS();

}


