//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_USER_H
#define PROGRAMMING_LAB_USER_H

#include <string>
#include <list>
#include <memory>
#include "Chat.h"

class Chat;

class User {
public:
    explicit User(std::string name = "") : realName(name) {}

    ~User() {}


    void setRealName(const std::string name) {
        User::realName = name;
    }

    std::string getRealName() const {
        return realName;
    }

    int numberOfChats() {
        return chats.size();
    }

    void addChat(const Chat &chat);

    int getNumOfUnreadChats();


    Chat *openAChat(int number);

    bool noChats();

private:
    std::string realName;
    std::vector<Chat> chats;
};

#endif //PROGRAMMING_LAB_USER_H
