//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_CHAT_H
#define PROGRAMMING_LAB_CHAT_H

#include <vector>
#include "User.h"
#include "Message.h"

class User;

class Chat {
public:

    Chat(const User &sender, const User &receiver, std::string name);

    virtual ~Chat();

    void addMessage(Message &text);


    Message * getLastMessage() {
        return chatMessages.back();
    }

    int numberOfMessages() {
        return chatMessages.size();
    }

    int numOfUnreadMessages();

    std::_List_iterator<Message *> openMessage();


    std::string getSenderName();

    std::string getReceiverName();

    std::string getChatName();


private:
    std::list<Message*> chatMessages;
    std::string senderName;
    std::string receiverName;
    std::string chatName;
};

#endif //PROGRAMMING_LAB_CHAT_H
