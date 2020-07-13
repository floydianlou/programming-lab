//
// Created by alice on 08/07/20.
//


#include "gtest/gtest.h"
#include "../Program.h"

User user1 ("Alice");
Program program(&user1);

//TEST(Program, tests) {
//    ASSERT_THROW(program.init(), std::out_of_range);
//}