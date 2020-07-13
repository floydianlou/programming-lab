cmake_minimum_required(VERSION 3.14)
project(programming_lab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)
set (SOURCE_FILES Chat.cpp User.cpp ProgramManager.cpp functions.cpp test/runAllTests.cpp Interface.h TextUserInterface.cpp TextUserInterface.h)
add_executable (programming_lab main.cpp)
add_library (core ${SOURCE_FILES})
target_link_libraries (programming_lab core)

