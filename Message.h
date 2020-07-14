#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-pass-by-value"
//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_MESSAGE_H
#define PROGRAMMING_LAB_MESSAGE_H

#include <string>
#include <iostream>
#include <ctime>

class Message {
public:

    Message(std::string sender, std::string receiver, std::string text, int ID, bool isread = false) : senderName(
            sender), receiverName(receiver), messageText(text), read(isread), messageID(ID) {
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

    int getMessageId() const {
        return messageID;
    }

    bool operator!=(const Message &right) const {
        return !(right == *this);
    }


    time_t getCurrentTime() const {
        return currentTime;
    }

private:
    std::string senderName;
    std::string receiverName;
    std::string messageText;
    bool read;
    time_t currentTime;
    int messageID;
};

#endif //PROGRAMMING_LAB_MESSAGE_H

#pragma clang diagnostic pop