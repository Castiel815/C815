#include "library.h"

#include <iostream>
#include <utility>

SQLConnect::SQLConnect(std::string host, std::string user, std::string passwd,
                       std::string db)
    : host(std::move(host)), user(std::move(user)), passwd(std::move(passwd)), db(std::move(db)),
      mysql_driver(sql::mysql::get_driver_instance()) {
}
