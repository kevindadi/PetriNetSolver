cmake_minimum_required(VERSION 3.23)
project(PetriNetSolver)

set(CMAKE_CXX_STANDARD 14)
set(TinyXML "/home/kevin/Desktop/PetriNetSolver/third_party/tinyxml2")

include_directories(${TinyXML})
find_library(XML tinyxml2 STATIC "${TinyXML}/build")
include_directories(${PROJECT_SOURCE_DIR}/include)

#link_libraries(${XML})

add_executable(PetriNetSolver main.cpp
        include/PetriNet.h include/ReachGraph.h include/XmlParse.h
        src/PetriNet.cpp src/ReachGraph.cpp src/XmlParse.cpp)
target_link_libraries(PetriNetSolver ${XML})
