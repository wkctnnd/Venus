cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(${VenusInc}/RenderEngine)

FILE(GLOB_RECURSE FILE_SOURCE ./*.cpp)
FILE(GLOB_RECURSE RENDERENGINE_HEADER ${VenusInc}/RenderEngine/*.h)

set(all_files ${FILE_SOURCE} ${RENDERENGINE_HEADER})
source_group_by_dir(sources)

ADD_LIBRARY(RenderEngine STATIC ${FILE_SOURCE} ${RENDERENGINE_HEADER})