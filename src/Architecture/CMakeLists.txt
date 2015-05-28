cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(${VenusInc}/Architecture)

FILE(GLOB_RECURSE FILE_SOURCE ./*.cpp)
FILE(GLOB_RECURSE FILE_HEADER ${VenusInc}/Architecture/*.h)

set(all_files ${FILE_SOURCE} ${FILE_HEADER})
source_group_by_dir(sources)

ADD_LIBRARY(Architecture STATIC ${FILE_SOURCE} ${FILE_HEADER})