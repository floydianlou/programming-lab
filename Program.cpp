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



void Program::login() {
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;
    auto itr = allUsers.find(username);
    if (itr != allUsers.end()) {
        currentUser = itr->second;
        std::cout << "Username found. Accessing main menu." << std::endl;
        mainMenu();
    } else {
        std::cout << "Username not found. Creating a new user." << std::endl;
        auto newUser = new User(username);
        addUser(newUser);
        currentUser = newUser;
        std::cout << "New user added. Accessing main menu." << std::endl;
        std::cout << "\t\t\t\t\t-----------------------------" << std::endl;
        mainMenu();
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

