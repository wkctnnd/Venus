cmake_minimum_required(VERSION 2.8)

FILE(GLOB_RECURSE SOURCE_1 *.cpp)
FILE(GLOB_RECURSE SOURCE_2 ${VenusInc}/Graphics/Common/*.h)

ADD_LIBRARY(Common STATIC ${SOURCE_1} ${SOURCE_2})