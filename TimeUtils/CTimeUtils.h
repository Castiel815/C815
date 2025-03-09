//
// Created by CY815 on 2024/2/20.
//

#ifndef C815_CTIMEUTILS_H
#define C815_CTIMEUTILS_H

#include <cstdint>
#include <ctime>
#include "commonHeader.h"
#include <string>
#include <sstream>

namespace utils {

    class CTimeUtils final {
    public:
        CTimeUtils();
        ~CTimeUtils();

        /**
         * =========================================================================================
         * 下面4个获取时间戳函数用于计算时间间隔，获取的时间起点不是1970-01-01 00:00:00 UTC
         */

        /**
         * 获取时间戳-秒
         * @return 时间戳-秒
         */
        static uint64_t getTimestampS();

        /**
         * 获取时间戳-毫秒
         * @return 时间戳-毫秒
         */
        static uint64_t getTimestampMilliS();

        /**
         * 获取时间戳-微秒
         * @return 时间戳-微秒
         */
        static uint64_t getTimestampMicroS();

        /**
         * 获取时间戳-纳秒
         * @return 时间戳-纳秒
         */
        static uint64_t getTimestampNanoseS();

        static std::time_t getCurrentTime();
        static std::string toString(time_t time, const std::string &format = "%Y-%m-%d %H:%M:%S");
    private:
        std::time_t m_t;
    };

} // utils

#endif //C815_CTIMEUTILS_H
