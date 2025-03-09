cmake_minimum_required(VERSION 3.30)
project(sqlConnect)

set(CMAKE_CXX_STANDARD 17)

set(APP_NAME sqlConnect)

include_directories(
        "D:/workspace/mysql-connector-c++-9.1.0-winx64/include"
)

add_library(${APP_NAME} SHARED library.cpp
        DBException.cpp
        DBException.h
        MySQLResultSet.cpp
        MySQLResultSet.h
        MySQLDB.cpp
        MySQLDB.h)

target_compile_definitions(${APP_NAME} PRIVATE MYLIB_EXPORTS)

target_link_libraries(${APP_NAME}
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/mysqlcppconn.lib"
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/mysqlcppconnx.lib"
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/libssl.lib"
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/libcrypto.lib"
)
