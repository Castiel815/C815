cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

set(APP_NAME timeUtilsTest)

set(SRC_HEADER

)

set(SRC_CPP
        timeUtilsTest.cpp
)

set(SRC_LIST
        ${SRC_HEADER}
        ${SRC_CPP}
)

include_directories(
        ${TIME_UTILS_INCLUDE_DIR}
)

link_directories(

)

add_executable(${APP_NAME} ${SRC_LIST})
set_target_properties(${APP_NAME} PROPERTIES FOLDER "timeUtilsTest")

target_link_libraries(${APP_NAME}
        timeUtils
)

if (WIN32)
    target_link_libraries(${APP_NAME}

    )
else (WIN32)
    target_link_libraries(${APP_NAME}

    )
endif (WIN32)
