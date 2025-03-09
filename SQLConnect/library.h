#ifndef SQLCONNECT_LIBRARY_H
#define SQLCONNECT_LIBRARY_H

#include <mysql/jdbc.h>

class SQLConnect {
public:
    SQLConnect(std::string host, std::string user, std::string passwd, std::string db);

    ~SQLConnect();

    bool connect();

    void disconnect();

private:
    std::string host;
    std::string user;
    std::string passwd;
    std::string db;
    std::unique_ptr<sql::Connection> conn;
    sql::mysql::MySQL_Driver *mysql_driver;
};

#endif //SQLCONNECT_LIBRARY_H
