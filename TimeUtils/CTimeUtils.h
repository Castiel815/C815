//
// Created by CY815 on 2024/2/20.
//

#ifndef C815_CTIMEUTILS_H
#define C815_CTIMEUTILS_H

#include <ctime>
#include "commonHeader.h"
#include <string>
#include <sstream>

namespace utils {

    class CTimeUtils final {
    public:
        CTimeUtils();
        ~CTimeUtils();

        static std::time_t getCurrentTime();
        static std::string toString(time_t time, const std::string &format = "%Y-%m-%d %H:%M:%S");
    private:
        std::time_t m_t;
    };

} // utils

#endif //C815_CTIMEUTILS_H
