cmake_minimum_required(VERSION 3.10)
project(DB)

set(CMAKE_CXX_STANDARD 11)

add_executable(DB
        testDB.cpp SQLRequester.cpp SQLRequester.h SQLRequesterTest.cpp SQLRequesterTest.h)

target_link_libraries (DB mysqlcppconn)
