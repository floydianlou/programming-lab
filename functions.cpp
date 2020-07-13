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

bool loginChoice(std::string choice) {
    if (choice == "A" || choice == "a") {
        return true;
    } else if (choice == "B" || choice == "b") {
        return false;
    } else {
        throw std::out_of_range("No correct choice was made.");
    }
}

void chatInfo(Chat itr) {
    std::cout << "Chat name: " << itr.getChatName() << std::endl;
    std::cout << "Sender: " << itr.getSenderName() << " - Receiver: " << itr.getReceiverName() << std::endl;
    std::cout << "Last message: ";
    auto message = itr.getLastMessage();
    auto time = timeToString(message->getCurrentTime());
    std::cout << time << " from: " << message->getSenderName() << " - " << message->getMessageText(); std::cout << std::endl;
    std::cout << "This chat has " << itr.numOfUnreadMessages() << " unread messages." << std::endl;
    std::cout << std::endl;
}

bool noChats(User * user) {
    if (user->noChats()) {
        std::cout << "There are currently no chats in your account." << std::endl;
        return true;
    } else {
        return false;
    }
}

void printChats(User *user) {
    if(!noChats(user)) {
        for (int i = 0; i < user->numberOfChats(); i++) {
            auto itr = user->openAChat(i);
            std::cout << "Chat n. " << i + 1 << std::endl;
            chatInfo(itr);
        }
    }
}

void printUnreadChats (User * user) {
    if(!noChats(user)) {
        for (int i = 0; i < user->numberOfChats(); i++) {
            auto itr = user->openAChat(i);
            if (itr.numOfUnreadMessages() > 0) {
                chatInfo(itr);
            }
        }
    }
}


void numOfUnreadChats(User *user) {
    int numberOfChats = user->getNumOfUnreadChats();
    std::cout << "You have " << numberOfChats << " chat(s) with unread messages." << std::endl;
}

void printMessageInfo(Message *text) {
    std::string time = timeToString(text->getCurrentTime());
    std::cout << time << " ";
    std::cout << "From: " << text->getSenderName() << " - Read (0/1): " << text->isRead() << std::endl;
    std::cout << text->getMessageText() << std::endl;
}

void printChatMessages(User *user, int chatNumber) {
    auto itr = user->openAChat(chatNumber);
    auto firstText = itr.openMessage();
    for (int count = 0; count < itr.numberOfMessages(); count++) {
        printMessageInfo(*firstText);
        std::advance(firstText, 1);
    }
}

void changeUserUsername (std::string newUsername, User * user) {
    user->setRealName(newUsername);
    std::cout << "Username changed to " << user->getRealName() << "." << std::endl;
}