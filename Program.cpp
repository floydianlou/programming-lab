//
// Created by alice on 02/07/20.
//

#include <iostream>
#include "Program.h"

void Program::addUser(User *newuser) {
    allUsers.insert(std::make_pair(newuser->getRealName(), newuser));
}


bool Program::loginChoice(std::string choice) {
    if (choice == "A" || choice == "a") {
       return true;
    } else if (choice == "B" || choice == "b") {
       return false;
    } else {
        throw std::out_of_range("No correct choice was made.");
    }
}



bool Program::isUsernameInList(std::string username) {
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

Program::~Program() {

}

User *Program::getCurrentUser() const {
    return currentUser;
}

time_t Program::getCurrentTime() const {
    return currentTime;
}

