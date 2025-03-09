//
// Created by CY815 on 2025/1/19.
//

// #include <mysql/jdbc.h>
#include "../../SQLConnect/MySQLDB.h"
#include "../../SQLConnect/DBException.h"
#include <iostream>

void testMySqlDB() {
    try {
        MySQLDB db("192.168.1.10", "root", "mysqlPass0>", "weather");
        auto result = db.executeQuery("select code, city_name from city_table");
        while (result.next()) {
            std::cout << "code = " << result.getString("code") << std::endl;
            std::cout << "city_name = " << result.getString("city_name") << std::endl;
        }
    } catch (const DBException &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {

    testMySqlDB();

    // try {
    //     sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
    //     sql::Connection* con = driver->connect("tcp://192.168.1.10:3306", "root", "mysqlPass0>");
    //     sql::Statement* stmt = con->createStatement();
    //     sql::ResultSet* res = stmt->executeQuery("select * from weather.city_table");
    //     while (res->next()) {
    //         std::cout << "row: " << res->getString("city_name") << std::endl;
    //     }
    //     delete res;
    //     delete stmt;
    //     delete con;
    // } catch(...) {
    //     std::cout << "Exception occured" << std::endl;
    // }

    return 0;
}
