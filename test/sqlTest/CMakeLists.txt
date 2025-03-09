cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

set(APP_NAME sqlTest)

set(SRC_HEADER

)

set(SRC_CPP

)

set(SRC_LIST
        sqlTest.cpp
)

include_directories(
        "D:/workspace/mysql-connector-c++-9.1.0-winx64/include"
        "../../../sqlConnect"
)

link_directories(
#        "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64"
)

add_executable(${APP_NAME} ${SRC_LIST})
set_target_properties(${APP_NAME} PROPERTIES FOLDER "sqlTest")

target_link_libraries(${APP_NAME}
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/mysqlcppconn.lib"
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/mysqlcppconnx.lib"
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/libssl.lib"
        debug "D:/workspace/mysql-connector-c++-9.1.0-winx64/lib64/Debug/vs14/libcrypto.lib"
        debug "D:/workspace/CLion/C815/cmake-build-debug-visual-studio/lib/Debug/sqlConnectd.lib"
)

if (WIN32)
    target_link_libraries(${APP_NAME}

    )
else (WIN32)
    target_link_libraries(${APP_NAME}

    )
endif (WIN32)