//
// Created by alice on 08/07/20.
//


#include "gtest/gtest.h"
#include "../Message.h"


TEST(Message, GettersSetters) {
    Message m("Alice", "Luca", "Hey, come va?", 12);
    ASSERT_EQ(m.getSenderName(), "Alice");
    ASSERT_EQ(m.getReceiverName(), "Luca");
    ASSERT_EQ(m.getMessageText(), "Hey, come va?");
    ASSERT_EQ(m.isRead(), false);
    m.setRead(true);
    ASSERT_EQ(m.isRead(), true);
    ASSERT_EQ(m.getMessageId(),12);
}
