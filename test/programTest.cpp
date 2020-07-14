//
// Created by alice on 08/07/20.
//


#include "gtest/gtest.h"
#include "../ProgramManager.h"

User user1("Alice"), user3("Luca");
ProgramManager program(&user1);

TEST(Program, tests) {
    program.addUser(&user3);
    ASSERT_TRUE(program.isUsernameInList("Luca"));
    ASSERT_EQ(program.getCurrentUser()->getRealName(), "Luca");
    ASSERT_FALSE(program.isUsernameInList("Olivia"));
}