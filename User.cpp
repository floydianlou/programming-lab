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
    int i = 1;
    for(auto itr : chats) {
        std::cout << "Chat n. " << i << std::endl;
        itr.printInfo();
        i++;
    }
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