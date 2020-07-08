//
// Created by alice on 02/07/20.
//


#include <iostream>
#include "User.h"


void User::changeUsername() {
    std::string newName;
    std::cout << "Enter your new username: "; std::cin >> newName;
    setRealName(newName);
    std::cout << "Username changed to " << realName << "." << std::endl;
}

void User::addChat(Chat chat) {
    chats.push_back(chat);
}

void User::printAllChats() {
    if (chats.empty()) {
        std::cout << "There are currently no chats in your account." << std::endl;
    } else { int i = 1;
    for(auto itr : chats) {
        std::cout << "Chat n. " << i << std::endl;
        itr.printInfo();
        i++; }
    }
}

bool User::noChats() {
    return chats.empty();
}

void User::openchat(int number) {
    number--;
    if(number >= 0 && number < chats.size()) {
    chats[number].readMessages();
    std::cout << std::endl; std::cout << "\t\t\t\t\t-----------------------------" << std::endl << std::endl;}
    else {
        throw std::out_of_range ("Could not find requested chat.");
    }

}

void User::getUnreadChats() {
    int count = 0;
    for (auto itr : chats) {
        if (!itr.getLastMessage().isRead()) {
            itr.printInfo();
        } else {
            count++;
        }
    } if (count == chats.size()) {
        std::cout << std::endl << "There are no unread messages nor chats." << std::endl;
    }
}