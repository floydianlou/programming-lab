//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_PROGRAM_H
#define PROGRAMMING_LAB_PROGRAM_H

#include "User.h"
#include <ctime>
#include <map>

class Program {
public:

    explicit Program(User * use) : currentUser(use) {
        ::time(&currentTime);
        allUsers.insert(std::make_pair(currentUser->getRealName(), currentUser));
    }

    void addUser(User * newuser);
    void init();

    virtual ~Program();

protected:

    void choices();
    void mainMenu();
    void login();

private:
    User * currentUser;
    time_t currentTime;
    std::map<std::string, User *> allUsers;
};

#endif //PROGRAMMING_LAB_PROGRAM_H
