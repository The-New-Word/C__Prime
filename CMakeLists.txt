cmake_minimum_required(VERSION 3.8)
project(C__Prime)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Chapter4.cpp Function.cpp HomeWork.cpp
        Sales_data.cpp Persion.cpp Chapter7.cpp Window_mgr.cpp Screen.cpp Debug.cpp Account.cpp Chapter8.cpp Chapter9.cpp)
set(HEAD Header.h HomeHead.h Sales_data.h Persion.h Window_mgr.h Screen.h
        Debug.h Account.h)

add_executable(C__Prime ${SOURCE_FILES} ${HEAD})