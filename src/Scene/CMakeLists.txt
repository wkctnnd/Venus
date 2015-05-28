cmake_minimum_required(VERSION 2.8)
INCLUDE_DIRECTORIES(${VenusInc}/Scene)
INCLUDE_DIRECTORIES(${VenusInc}/Container)

 
FILE(GLOB_RECURSE SCENE_SOURCE ${VenusSrc}/Scene/*.cpp)

FILE(GLOB_RECURSE SCENE_HEADER ${VenusInc}/Scene/*.h)


List(APPEND sources ${SCENE_SOURCE} ${SCENE_HEADER})

source_group_by_dir(sources)


ADD_LIBRARY(Scene STATIC ${SCENE_SOURCE} ${SCENE_HEADER})
