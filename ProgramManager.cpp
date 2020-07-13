//
// Created by alice on 02/07/20.
//

#include <iostream>
#include "ProgramManager.h"

void ProgramManager::addUser(User *newuser) {
    allUsers.insert(std::make_pair(newuser->getRealName(), newuser));
}



bool ProgramManager::isUsernameInList(std::string username) {
    auto itr = allUsers.find(username);
    if (itr != allUsers.end()) {
        currentUser = itr->second;
        return true;
    } else {
        auto newUser = new User(username);
        addUser(newUser);
        currentUser = newUser;
        return false;
    }
}

ProgramManager::~ProgramManager() {

}

User *ProgramManager::getCurrentUser() const {
    return currentUser;
}

time_t ProgramManager::getCurrentTime() const {
    return currentTime;
}

