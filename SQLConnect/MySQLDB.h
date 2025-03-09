//
// Created by CY815 on 2025/2/25.
//

#ifndef MYSQLDB_H
#define MYSQLDB_H

#ifdef _WIN32
    #ifdef MYLIB_EXPORTS
        #define MYLIB_API __declspec(dllexport)
    #else
        #define MYLIB_API __declspec(dllimport)
    #endif
#else
    #define MYLIB_API __attribute__((visibility("default")))
#endif

#include "MySQLResultSet.h"

class MYLIB_API MySQLDB {
public:
    MySQLDB(const std::string &host, const std::string &user, const std::string &passwd, const std::string &database,
            unsigned int port = 3306);

    void execute(const std::string &query) const;

    [[nodiscard]] MySQLResultSet executeQuery(const std::string &query) const;

    void beginTransaction() const;

    void commit() const;

    void rollback() const;

    template<typename ...Args>
    void prepareExecute(const std::string &query, Args... args);

private:
    sql::mysql::MySQL_Driver *driver;
    std::unique_ptr<sql::Connection> connection;

    template<typename T, typename... Args>
    void bindParameters(std::unique_ptr<sql::PreparedStatement> &pstmt,
        int index, T value);
    void bindParameters(std::unique_ptr<sql::PreparedStatement>&, int);
};


#endif //MYSQLDB_H
