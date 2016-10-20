cmake_minimum_required(VERSION 3.6)
project(ParseSlimQuick)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Signature.cpp Signature.h Sequence.cpp Sequence.h Sequences.cpp Sequences.h)
add_executable(ParseSlimQuick ${SOURCE_FILES})


find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})