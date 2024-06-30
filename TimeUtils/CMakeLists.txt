cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

set(APP_NAME timeUtils)

set(SRC_HEADER
        commonHeader.h
        CTimeUtils.h
)

set(SRC_IMPL
        CTimeUtils.cpp
)

set(SRC_LIST
        ${SRC_HEADER}
        ${SRC_IMPL}
)

include_directories(

)

link_directories(

)

add_library(${APP_NAME} STATIC ${SRC_LIST})

set_target_properties(${APP_NAME} PROPERTIES FOLDER "timeUtils")

if (WIN32)
    target_link_libraries(${APP_NAME}

    )
else (WIN32)
    target_link_libraries(${APP_NAME}

    )
endif (WIN32)
