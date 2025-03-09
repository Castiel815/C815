//
// Created by CY815 on 2025/2/25.
//

#ifndef MYSQLRESULTSET_H
#define MYSQLRESULTSET_H

#ifdef _WIN32
    #ifdef MYLIB_EXPORTS
        #define MYLIB_API __declspec(dllexport)
    #else
        #define MYLIB_API __declspec(dllimport)
    #endif
#else
    #define MYLIB_API __attribute__((visibility("default")))
#endif

#include <mysql/jdbc.h>
#include <memory>

class MYLIB_API MySQLResultSet {
public:
    explicit MySQLResultSet(std::unique_ptr<sql::ResultSet> rs);

    [[nodiscard]] bool next() const;

    [[nodiscard]] int getInt(const std::string &column) const;

    [[nodiscard]] std::string getString(const std::string &column) const;

private:
    void checkNull(const std::string &column) const;

    std::unique_ptr<sql::ResultSet> result_set;
};


#endif //MYSQLRESULTSET_H
