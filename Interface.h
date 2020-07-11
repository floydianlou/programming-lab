//
// Created by alice on 11/07/20.
//

#ifndef PROGRAMMING_LAB_INTERFACE_H
#define PROGRAMMING_LAB_INTERFACE_H

#include "Program.h"

class Interface {
public:
    Interface(Program *prog) : program(prog) {}

    virtual void beginProgram() = 0;

    virtual ~Interface() {

    }

protected:
    Program * program;
};

#endif //PROGRAMMING_LAB_INTERFACE_H
