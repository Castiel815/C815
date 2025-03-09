//
// Created by CY815 on 2025/2/25.
//

#ifndef DBEXCEPTION_H
#define DBEXCEPTION_H

#include <stdexcept>

class DBException : public std::runtime_error {
public:
    DBException(const std::string &msg, const int code = -1) : std::runtime_error(msg), error_code(code) {
    }

    [[nodiscard]] int getErrorCode() const noexcept { return error_code; }

private:
    int error_code;
};


#endif //DBEXCEPTION_H
