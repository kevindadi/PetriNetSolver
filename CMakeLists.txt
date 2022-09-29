cmake_minimum_required(VERSION 3.23)
project(PetriNetSolver)

set(CMAKE_CXX_STANDARD 14)
set(TinyXML "/home/kevin/Desktop/PetriNetSolver/third_party/tinyxml2")

include_directories(include, ${TinyXML})


add_executable(PetriNetSolver src/main.cpp
        include/XmlParse.h include/PetriNet.h include/ReachGraph.h
        src/XmlParse.cpp src/PetriNet.cpp src/ReachGraph.cpp)

link_libraries(PetriNetSolver "libtinyxml2.a")