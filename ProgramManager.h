//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_PROGRAMMANAGER_H
#define PROGRAMMING_LAB_PROGRAMMANAGER_H

#include "User.h"
#include <ctime>
#include <map>

class ProgramManager {
public:

    explicit ProgramManager(User *use) : currentUser(use) {
        ::time(&currentTime);
        allUsers.insert(std::make_pair(currentUser->getRealName(), currentUser));
    }

    void addUser(User *newuser);

    User *getCurrentUser() const;

    time_t getCurrentTime() const;

    virtual ~ProgramManager();

    bool isUsernameInList(std::string username);

private:
    User *currentUser;
    time_t currentTime;
    std::map<std::string, User *> allUsers;
};

#endif //PROGRAMMING_LAB_PROGRAMMANAGER_H
