cmake_minimum_required(VERSION 2.8)
ADD_SUBDIRECTORY(Image Image)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/Resource)

FILE(GLOB_RECURSE FILE_SOURCE ./*.cpp)
FILE(GLOB_RECURSE FILE_HEADER ./*.h)

set(all_files ${FILE_SOURCE} ${FILE_HEADER})
source_group_by_dir(sources)

ADD_LIBRARY(Resource STATIC ${FILE_SOURCE} ${FILE_HEADER})