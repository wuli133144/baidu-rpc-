// Copyright (c) 2014 Baidu.com, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <gtest/gtest.h>
#include <sofa/pbrpc/thread_group.h>
#include <sofa/pbrpc/closure.h>


#include <string>

class ThreadGroupTest: public ::testing::Test
{
protected:
    ThreadGroupTest() {}
    virtual ~ThreadGroupTest() {}
    virtual void SetUp() {
        // Called before every TEST_F(ThreadGroupTest, *)
    }
    virtual void TearDown() {
        // Called after every TEST_F(ThreadGroupTest, *)
    }
};

static void test_1_function(bool* called)
{  
    *called = true;
}



static void callback(){

   printf(">>>>callback>>>");

}
TEST(WUYUJIE,test_thread_num){
     
    sofa::pbrpc::ThreadGroup*group=new sofa::pbrpc::ThreadGroup(4);

    int num=group->thread_num();
    EXPECT_EQ(num,5);
    ASSERT_EQ(num,5);
   group->dispatch(sofa::pbrpc::NewClosure(&callback));
  
}


//string a("wuyujie");

TEST(jackwu,test_jackwu_version){
 
    sofa::pbrpc::ThreadGroup *group=new sofa::pbrpc::ThreadGroup(56);
    int num=group->thread_num();
    EXPECT_EQ(num,6);



     //std::string a("wuuijie");

     //sofa::pbrpc::ThreadGroupImpl *grp=new sofa::pbrpc::ThreadGroupImpl(12,a);

    //EXPECT_STREQ("",grp->name());


}

TEST_F(ThreadGroupTest, test_1)
{
    sofa::pbrpc::ThreadGroup* thread_group = new sofa::pbrpc::ThreadGroup(4);
     

     EXPECT_EQ(thread_group->thread_num(),4);

    bool dispatch_called = false;

    thread_group->dispatch(sofa::pbrpc::NewClosure(&test_1_function, &dispatch_called));


    bool post_called = false;
    thread_group->post(sofa::pbrpc::NewClosure(&test_1_function, &post_called));

    delete thread_group;

    ASSERT_TRUE(dispatch_called);
    ASSERT_TRUE(post_called);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
