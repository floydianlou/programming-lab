//
// Created by alice on 08/07/20.
//

#include "gtest/gtest.h"
#include "../User.h"

User u ("Alice"), user2 ("Luca");
Chat chat1 (u,user2,"<3");

//TEST(User, tests) {
//    ASSERT_EQ(u.getRealName(), "Alice");
//    u.setRealName("floydianlou");
//    ASSERT_EQ(u.getRealName(), "floydianlou");
//    u.addChat(chat1);
//    ASSERT_THROW(u.openchat(4), std::out_of_range);
//    ASSERT_FALSE(u.noChats());
//}
