//
// Created by alice on 02/07/20.
//


#include <ctime>
#include <iostream>
#include <limits>

void timetime(time_t currentTime) {
    char timey [100];
    time_t time = currentTime;
    struct tm *localTime = localtime (& time);
    strftime(timey, 100, "%I:%M%p", localTime);
    std::cout << timey;
}

void cinFail() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl; }
}

