//
// Created by alice on 02/07/20.
//


#include <iostream>
#include "Chat.h"

Chat::Chat(const User& sender, const User& receiver, std::string name) : senderName(sender.getRealName()), receiverName(receiver.getRealName()), chatName(std::move(name)){}

void Chat::addMessage(Message& text) {
    if((text.getSenderName() == senderName || text.getSenderName() == receiverName) && (text.getReceiverName() == receiverName || text.getReceiverName() == senderName)) {
    chatMessages.push_back(text);
    } else {
    throw std::invalid_argument("Sender or receiver don't match.");
    }
}


void Chat::printInfo() {
    std::cout << "Chat name: " << chatName << std::endl;
    std::cout << "Sender: " << senderName << " - Receiver: " << receiverName << std::endl;
    std::cout << "Last message: "; getLastMessage().printText(); std::cout << std::endl;
}

void Chat::readMessages() {
    for (auto &chatMessage : chatMessages) {
        if(!chatMessage.isRead()) {
        chatMessage.setRead(true); }
        chatMessage.printText();
    }
}


std::string Chat::getSenderName() {
    return senderName;
}

std::string Chat::getReceiverName() {
    return receiverName;
}

std::string Chat::getChatName() {
    return chatName;
}

Chat::~Chat() {

}

