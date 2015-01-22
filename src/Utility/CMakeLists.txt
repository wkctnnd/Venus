cmake_minimum_required(VERSION 2.8)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/Utility)


ADD_SUBDIRECTORY(File File)
ADD_SUBDIRECTORY(Memory Memory)

FILE(GLOB_RECURSE SOURCE_1 *.cpp)
FILE(GLOB_RECURSE SOURCE_2 *.h)

set(all_files ${SOURCE_1} ${SOURCE_2})

source_group_by_dir(all_files)


ADD_LIBRARY(Utility STATIC ${SOURCE_1} ${SOURCE_2})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/binary/lib)