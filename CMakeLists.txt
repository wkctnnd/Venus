cmake_minimum_required(VERSION 2.8)
PROJECT(Venus)

#set venus top directory
set(VenusDir ${CMAKE_CURRENT_SOURCE_DIR})

#set sdk directory
set(VenusInc ${CMAKE_CURRENT_SOURCE_DIR}/include)

#set src directory
set(VenusSrc ${CMAKE_CURRENT_SOURCE_DIR}/src)

#set build directory
Set(VenusBuild ${CMAKE_CURRENT_SOURCE_DIR}/build)

#set binary directory
set(VenusBinary ${VenusBuild}/binary)

#set link path
LINK_DIRECTORIES( ${VenusBuild}/binary/bin/debug)

#set exe liboutput dir
SET(EXECUTABLE_OUTPUT_PATH ${VenusBinary}/bin)
SET(LIBRARY_OUTPUT_PATH ${VenusBinary}/bin)




include(${VenusDir}/sourcegroupbydir.txt)
include(${VenusDir}/globalinclude.txt)


ADD_SUBDIRECTORY(${VenusDir}/src)

ADD_SUBDIRECTORY(${VenusDir}/test)

INCLUDE_DIRECTORIES(${VenusInc}/Graphics)
#ADD_EXECUTABLE(test main.cpp)
#target_link_libraries(test DX11)















#SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)





