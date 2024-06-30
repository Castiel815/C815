//
// Created by CY815 on 2024/2/20.
//

#include "CTimeUtils.h"
#include <chrono>
#include <iomanip>

namespace utils {
    CTimeUtils::CTimeUtils() {
        m_t = 0;
    }

    CTimeUtils::~CTimeUtils() = default;

    std::time_t CTimeUtils::getCurrentTime() {
        const std::chrono::system_clock::time_point currTime = std::chrono::system_clock::now();
        const time_t time = std::chrono::system_clock::to_time_t(currTime);

        return time;
    }

    std::string CTimeUtils::toString(const time_t time, const std::string &format) {
        std::stringstream ss;
        tm t{};
#ifdef WIN32
        localtime_s(&t, &time);
#elif __linux__
        localtime_r(&time, &t);
#endif
        ss << std::put_time(&t, format.c_str());
        std::string stringTime = ss.str();
        return stringTime;
    }




} // utils