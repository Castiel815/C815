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

    uint64_t CTimeUtils::getTimestampS() {
        const std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();
        const long long timestamp = std::chrono::duration_cast<std::chrono::seconds>(currTime.time_since_epoch()).count();
        return timestamp;
    }

    uint64_t CTimeUtils::getTimestampMilliS() {
        const std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();
        const long long timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(currTime.time_since_epoch()).count();
        return timestamp;
    }

    uint64_t CTimeUtils::getTimestampMicroS() {
        const std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();
        const long long timestamp = std::chrono::duration_cast<std::chrono::microseconds>(currTime.time_since_epoch()).count();
        return timestamp;
    }

    uint64_t CTimeUtils::getTimestampNanoseS() {
        const std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();
        const long long timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(currTime.time_since_epoch()).count();
        return timestamp;
    }


    std::time_t CTimeUtils::getCurrentTime() {
        const std::chrono::system_clock::time_point currTime = std::chrono::system_clock::now();
        const time_t time = std::chrono::system_clock::to_time_t(currTime);

        return time;
    }

    std::string CTimeUtils::toString(const time_t time, const std::string &format) {
        std::stringstream ss;
        tm t{};
#ifdef _WIN32
        localtime_s(&t, &time);
#elif __linux__
        localtime_r(&time, &t);
#endif
        ss << std::put_time(&t, format.c_str());
        std::string stringTime = ss.str();
        return stringTime;
    }




} // utils