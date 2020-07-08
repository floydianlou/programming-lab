//
// Created by alice on 02/07/20.
//


#include <ctime>
#include <iostream>

void timetime(time_t currentTime) {
    char timey [100];
    time_t time = currentTime;
    struct tm *localTime = localtime (& time);
    strftime(timey, 100, "%I:%M%p", localTime);
    std::cout << timey;
}

