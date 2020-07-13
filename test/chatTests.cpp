//
// Created by alice on 08/07/20.
//


#include "gtest/gtest.h"
#include "../Chat.h"

User userAlice ("Alice"), userLuca ("Luca");
Chat chat (userAlice, userLuca, "<3");

TEST(Chat, GettersSetters){
    ASSERT_EQ(chat.getSenderName(), "Alice");
    ASSERT_EQ(chat.getReceiverName(), "Luca");
    ASSERT_EQ(chat.getChatName(), "<3");
}

//TEST(Chat, functions){
//    Message m ("Alice", "Luca", "Hey, come va?");
//    Message x ("Olivia", "Margherita", "Hey, come va?");
//    chat.addMessage(m);
//    ASSERT_EQ(chat.getLastMessage(), m);
//    ASSERT_THROW(chat.addMessage(x), std::invalid_argument);
//
//}
