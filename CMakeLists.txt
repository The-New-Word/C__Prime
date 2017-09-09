cmake_minimum_required(VERSION 3.8)
project(C__Prime)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Chapter4.cpp Function.cpp HomeWork.cpp Sales_data.cpp Persion.cpp Chapter7.cpp
        Window_mgr.cpp Screen.cpp Debug.cpp Account.cpp Chapter8.cpp Chapter9.cpp
        Chapter10.cpp Chapter11.cpp Chapter12.cpp strBlob.cpp StrBlobPtr.cpp Chapter13.cpp
        Text_Search.cpp StrVec.cpp Chapter14.cpp Chapter15.cpp )

set(HEAD
        Header.h HomeHead.h Sales_data.h Persion.h Window_mgr.h Screen.h
        Debug.h Account.h ch12.h strBlob.h StrBlobPtr.h Test.h Chapter13.h
        Text_Search.h StrVec.h  Chapter14.h Chapter15.h)

add_executable(C__Prime ${SOURCE_FILES} ${HEAD})