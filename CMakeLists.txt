cmake_minimum_required(VERSION 3.23)
project(PetriNetSolver)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_TOOLCHAIN_FILE /home/kevin/vcpkg/scripts/buildsystems/vcpkg.cmake)
#set(TinyXML "/home/kevin/Desktop/PetriNetSolver/third_party/tinyxml2")
#include_directories(${TinyXML})
#find_library(XML tinyxml2 STATIC "${TinyXML}/build")
#include_directories(${PROJECT_SOURCE_DIR}/include)

FIND_PACKAGE(Boost REQUIRED system log)
if(Boost_FOUND)
    message(STATUS "boost include path is : ${Boost_INCLUDE_DIRS}")
    message(STATUS "boost library path is : ${Boost_LIBRARY_DIRS}")
    message(STATUS "boost libraries is : ${Boost_LIBRARIES}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(WARNING "boost not found.")
endif()

find_package(tinyxml2 CONFIG REQUIRED)

add_executable(PetriNetSolver main.cpp
        include/PetriNet.h include/ReachGraph.h include/XmlParse.h
        src/PetriNet.cpp src/ReachGraph.cpp src/XmlParse.cpp)
target_link_libraries(PetriNetSolver PRIVATE tinyxml2::tinyxml2)
target_link_libraries(PetriNetSolver PUBLIC Boost::system Boost::log)