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

    Chat(User sender,User receiver, std::string name);

    void addMessage (Message& text);

    void printInfo();

    Message& getLastMessage() {
        return chatMessages.back();
    }

    void readMessages();

    std::string getSenderName();

    std::string getReceiverName();

    std::string getChatName();


private:
    std::vector<Message> chatMessages;
    std::string senderName;
    std::string receiverName;
    std::string chatName;
};

#endif //PROGRAMMING_LAB_CHAT_H
