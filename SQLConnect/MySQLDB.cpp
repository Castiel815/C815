//
// Created by CY815 on 2025/2/25.
//

#include "MySQLDB.h"

#include "DBException.h"

MySQLDB::MySQLDB(const std::string &host, const std::string &user, const std::string &passwd,
                 const std::string &database, const unsigned int port) {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        connection.reset(driver->connect(host + ":" + std::to_string(port), user, passwd));
        connection->setSchema(database);
    } catch (sql::SQLException &e) {
        throw DBException(e.what(), e.getErrorCode());
    }
}

void MySQLDB::execute(const std::string &query) const {
    if (!connection || connection->isClosed()) {
        throw DBException("Connection is invalid or closed");
    }

    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        stmt->execute(query);
    }
    catch (sql::SQLException &e) {
        throw DBException(e.what(), e.getErrorCode());
    }
}

MySQLResultSet MySQLDB::executeQuery(const std::string &query) const {
    try {
        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));
        return MySQLResultSet(std::move(res));
    }
    catch (sql::SQLException &e) {
        throw DBException(e.what(), e.getErrorCode());
    }
}

void MySQLDB::beginTransaction() const {
    try {
        connection->setAutoCommit(false);
    }
    catch (sql::SQLException &e) {
        throw DBException(e.what(), e.getErrorCode());
    }
}

void MySQLDB::commit() const {
    try {
        connection->commit();
        connection->setAutoCommit(true);
    }
    catch (sql::SQLException &e) {
        throw DBException(e.what(), e.getErrorCode());
    }
}

void MySQLDB::rollback() const {
    try {
        connection->rollback();
        connection->setAutoCommit(true);
    }
    catch (sql::SQLException &e) {
        throw DBException(e.what(), e.getErrorCode());
    }
}

template<typename... Args>
void MySQLDB::prepareExecute(const std::string &query, Args... args) {
    std::unique_ptr<sql::PreparedStatement> pstmt(connection->prepareStatement(query));
    int index = 1;
    (bindParameters(pstmt, index++, args),...);
    pstmt->executeUpdate();
}


template<typename T, typename... Args>
void MySQLDB::bindParameters(std::unique_ptr<sql::PreparedStatement> &pstmt, int index, T value) {
    if constexpr (std::is_integral_v<T> && !std::is_same_v<T, bool>) {
        pstmt->setInt(index, value);
    } else if constexpr (std::is_same_v<T, std::string>) {
        pstmt->setString(index, value);
    } else if constexpr (std::is_same_v<T, double>) {
        pstmt->setDouble(index, value);
    }
}

void MySQLDB::bindParameters(std::unique_ptr<sql::PreparedStatement> &, int) {

}
