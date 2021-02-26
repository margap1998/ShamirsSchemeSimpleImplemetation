cmake_minimum_required(VERSION 3.15)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(FLTK_DIR /usr/include/FL)
set(SOURCE_FILES main.cpp function/MainProgram.cpp function/MainProgram.h function/JoiningWindow.cpp function/JoiningWindow.h function/SchemeParter.cpp function/SchemeParter.h function/ILog.h function/SchemeJoiner.cpp function/SchemeJoiner.h function/functions.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} function/MainProgram.cpp function/MainProgram.h)
set(FLTK_SKIP_FLUID true)
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${FLTK_BASE_LIBRARY} ${FLTK_PLATFORM_DEPENDENT_LIBS})
