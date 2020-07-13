//
// Created by alice on 02/07/20.
//


#include <iostream>
#include "User.h"


void User::changeUsername() { //TODO high level function not in class
    std::string newName;
    std::cout << "Enter your new username: ";
    std::cin >> newName;
    setRealName(newName);
    std::cout << "Username changed to " << realName << "." << std::endl;
}

void User::addChat(Chat chat) {
    chats.push_back(chat);
}

Chat User::openAChat(int number) {
        if (number >= 0 && number < chats.size()) {
            return chats[number];
        } else {
            throw std::out_of_range("Could not find requested chat.");
        }

    }

bool User::noChats() {
    return chats.empty();
}

void User::openchat(int number) { //TODO modify method
    number--;
    if (number >= 0 && number < chats.size()) {
        chats[number].readMessages();
        std::cout << std::endl;
        std::cout << "\t\t\t\t\t-----------------------------" << std::endl << std::endl;
    } else {
        throw std::out_of_range("Could not find requested chat.");
    }

}

int User::getNumOfUnreadChats() {
    int count = 0;
    for (auto itr : chats) {
        if (!itr.getLastMessage().isRead())
            count++;
    }
    return count;
}