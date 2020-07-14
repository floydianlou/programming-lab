//
// Created by alice on 08/07/20.
//

#include "gtest/gtest.h"
#include "../User.h"

User u("Alice"), user2("Luca");
Chat chat1(u, user2, "<3");
Message m("Alice", "Luca", "Hey <3", 02, false);


TEST(User, tests) {
    ASSERT_EQ(u.getRealName(), "Alice");
    u.setRealName("floydianlou");
    ASSERT_EQ(u.getRealName(), "floydianlou");
    chat1.addMessage(m);
    u.addChat(chat1);
    ASSERT_EQ(u.getNumOfUnreadChats(), 1);
    auto chat2 = u.openAChat(0);
    ASSERT_EQ(chat2->getSenderName(), chat1.getSenderName());
    ASSERT_FALSE(u.noChats());
}
