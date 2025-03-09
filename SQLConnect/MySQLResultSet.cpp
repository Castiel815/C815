//
// Created by CY815 on 2025/2/25.
//

#include "MySQLResultSet.h"
#include "DBException.h"

MySQLResultSet::MySQLResultSet(std::unique_ptr<sql::ResultSet> rs) : result_set(std::move(rs)) {
}

bool MySQLResultSet::next() const {
    return result_set->next();
}

void MySQLResultSet::checkNull(const std::string &column) const {
    if (result_set->isNull(column)) {
        throw DBException("Null value in column: " + column);
    }
}

int MySQLResultSet::getInt(const std::string &column) const {
    checkNull(column);
    return result_set->getInt(column);
}

std::string MySQLResultSet::getString(const std::string &column) const {
    checkNull(column);
    return result_set->getString(column);
}
