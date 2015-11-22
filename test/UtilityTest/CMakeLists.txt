cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(${VenusInc}/Utility)

FILE(GLOB_RECURSE SOURCE_1 *.cpp)
FILE(GLOB_RECURSE HEADER_1 *.h)

ADD_EXECUTABLE(UtilityTest ../BaseTest.h ../BaseTest.cpp ${SOURCE_1} ${HEADER_1})

target_link_libraries(UtilityTest Utility)