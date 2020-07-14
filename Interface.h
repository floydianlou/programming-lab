//
// Created by alice on 11/07/20.
//

#ifndef PROGRAMMING_LAB_INTERFACE_H
#define PROGRAMMING_LAB_INTERFACE_H

#include "ProgramManager.h"

class Interface {
public:
    explicit Interface(ProgramManager *prog) : program(prog) {}

    virtual void beginProgram() = 0;

    virtual ~Interface() {

    }

protected:
    ProgramManager *program;
};

#endif //PROGRAMMING_LAB_INTERFACE_H
