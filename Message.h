//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_MESSAGE_H
#define PROGRAMMING_LAB_MESSAGE_H

#include <string>
#include <iostream>
#include <ctime>
#include "functions.h"

class Message {
public:

    Message(std::string sender, std::string receiver, std::string text, bool isread = false) : senderName(std::move(sender)), receiverName(std::move(receiver)), messageText(std::move(text)), read(isread) {
    time(&currentTime);
    }

    std::string getSenderName() const {
        return senderName;
    }

    std::string getReceiverName() const {
        return receiverName;
    }

    bool isRead() const {
        return read;
    }

    void setRead(bool r) {
        read = r;
    }

    std::string getMessageText() {
        return messageText;
    }



    bool operator==(const Message &right) const {
        return senderName == right.senderName &&
               receiverName == right.receiverName &&
               messageText == right.messageText;
    }

    bool operator!=(const Message & right) const {
        return !(right ==*this);
    }

    void printText() {
        timetime(currentTime); std::cout << " ";
        std::cout << "From: " << senderName << " - Read (0/1): " << read << std::endl;
        std::cout << messageText << std::endl;
    }


private:
    std::string senderName;
    std::string receiverName;
    std::string messageText;
    bool read;
    time_t currentTime;
};

#endif //PROGRAMMING_LAB_MESSAGE_H
