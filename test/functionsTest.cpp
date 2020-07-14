//
// Created by alice on 14/07/20.
//


#include "gtest/gtest.h"
#include "../functions.h"

User user4 ("Alice"), user5 ("Luca");
Chat chat3 (user4, user5, "<3");
Message mx ("Alice", "Luca", "Hey!", 1);


TEST (functions, tests) {
    ASSERT_THROW(loginChoice("3"), std::out_of_range);
    ASSERT_TRUE(noChats(&user4));
    chat3.addMessage(mx);
    user4.addChat(chat3);
    ASSERT_EQ(chat3.numberOfMessages(), 1);
    deleteAMessage(&chat3, 1);
    ASSERT_EQ(chat3.numberOfMessages(), 0);
    changeUserUsername("floydianlou", &user4);
    ASSERT_EQ(user4.getRealName(), "floydianlou");
}
