cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

set(TIME_UTILS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/TimeUtils)

add_subdirectory(timeUtilsTest)
add_subdirectory(sqlTest)
