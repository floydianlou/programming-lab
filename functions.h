//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_FUNCTIONS_H
#define PROGRAMMING_LAB_FUNCTIONS_H

#include <ctime>
#include "User.h"

std::string timeToString(time_t currentTime);

void cinFail();

void numOfUnreadChats (User * user);

void printChats (User * user);

void printChatMessages (User * user, int chatNumber);

bool loginChoice(std::string choice);

void changeUserUsername (std::string newUsername, User * user);

void printUnreadChats (User * user);

bool noChats(User * user);

void deleteAMessage(Chat* chat, int IDNum);

#endif //PROGRAMMING_LAB_FUNCTIONS_H
