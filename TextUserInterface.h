//
// Created by alice on 11/07/20.
//

#ifndef PROGRAMMING_LAB_TEXTUSERINTERFACE_H
#define PROGRAMMING_LAB_TEXTUSERINTERFACE_H

#include "Interface.h"

class TextUserInterface : public Interface {
public:

    TextUserInterface(ProgramManager * prog) : Interface(prog) {

    }

    void beginProgram() override;
    void mainMenu();
    void choices();
    void login();
protected:

    bool noChatsToOpen();

};

#endif //PROGRAMMING_LAB_TEXTUSERINTERFACE_H
