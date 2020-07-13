//
// Created by alice on 02/07/20.
//


#include <ctime>
#include <iostream>
#include <limits>
#include "User.h"

std::string timeToString(time_t currentTime) {
    char timey[100];
    time_t time = currentTime;
    struct tm *localTime = localtime(&time);
    strftime(timey, 100, "%I:%M%p", localTime);
    return timey;
}

void cinFail() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
    }
}

void printChats(User * user) {
    if (user->noChats()) {
        std::cout << "There are currently no chats in your account." << std::endl;
    } else {
    for(int i = 0; i < user->numberOfChats(); i++) {
       auto itr =  user->openAChat(i);
        std::cout << "Chat name: " << itr.getChatName() << std::endl;
        std::cout << "Sender: " << itr.getSenderName() << " - Receiver: " << itr.getReceiverName() << std::endl;
        std::cout << "Last message: ";
        auto message = itr.getLastMessage();
        auto time = timeToString(message.getCurrentTime());
        std::cout << time << " from: " << message.getSenderName() << " - " << message.getMessageText();
        std::cout << std::endl;
    } }
}

void numOfUnreadChats(User *user) {
    int numberOfChats = user->getNumOfUnreadChats();
    std::cout << "You have " << numberOfChats << " chats with unread messages." << std::endl;
    //TODO fix and end
}

void printMessageInfo(Message *text) {
    std::string time = timeToString(text->getCurrentTime());
    std::cout << time << " ";
    std::cout << "From: " << text->getSenderName() << " - Read (0/1): " << text->isRead() << std::endl;
    std::cout << text->getMessageText() << std::endl;
}