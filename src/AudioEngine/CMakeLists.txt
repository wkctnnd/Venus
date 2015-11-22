cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(${VenusInc}/AudioEngine)

FILE(GLOB_RECURSE FILE_SOURCE ./*.cpp)
FILE(GLOB_RECURSE FILE_HEADER ${VenusInc}/AudioEngine/*.h)

set(all_files ${FILE_SOURCE} ${FILE_HEADER})
source_group_by_dir(sources)

ADD_LIBRARY(AudioEngine STATIC ${FILE_SOURCE} ${FILE_HEADER})