//
// Created by CY815 on 2024/2/20.
//

#include <chrono>
#include <iomanip>
#include <iostream>
#include <ctime>

#include "CTimeUtils.h"

void getCurrentTime() {
    std::chrono::system_clock::time_point tpoint = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(tpoint);
    tm *t = localtime(&tt);
    std::cout << std::put_time(t, "%Y-%m-%d %H:%M:%S") << std::endl;
}

void testTimeUtils() {
    utils::CTimeUtils time_utils;
    const time_t t = utils::CTimeUtils::getCurrentTime();
    std::cout << t << std::endl;

    std::cout << utils::CTimeUtils::toString(t) << "\n";
}

int main() {
    testTimeUtils();
    return 0;
}
