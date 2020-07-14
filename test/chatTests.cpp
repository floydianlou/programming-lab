//
// Created by alice on 08/07/20.
//


#include "gtest/gtest.h"
#include "../Chat.h"

User userAlice("Alice"), userLuca("Luca");
Chat chat(userAlice, userLuca, "<3");

TEST(Chat, GettersSetters) {
    ASSERT_EQ(chat.getSenderName(), "Alice");
    ASSERT_EQ(chat.getReceiverName(), "Luca");
    ASSERT_EQ(chat.getChatName(), "<3");

}

TEST(Chat, functions) {
    Message m("Alice", "Luca", "Hey, come va?", 19, true);
    Message x("Olivia", "Margherita", "Hey, come va?", 21);
    Message y("Alice", "Luca", "Ciao amore", 24);
    ASSERT_THROW(chat.addMessage(x), std::invalid_argument);
    chat.addMessage(m);
    chat.addMessage(y);
    ASSERT_EQ(chat.getLastMessage(), &y);
    ASSERT_EQ(chat.numberOfMessages(),2);
    ASSERT_EQ(chat.numOfUnreadMessages(),1);
    chat.deleteMessage(24);
    ASSERT_EQ(chat.getLastMessage(), &m);
    ASSERT_THROW(chat.deleteMessage(3), std::out_of_range);
    ASSERT_EQ(chat.numOfUnreadMessages(),0);
}
