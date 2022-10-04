//
// Created by kevin on 22-9-29.
//


#include <iostream>
#include "include/XmlParse.h"
#include "include/ReachGraph.h"
#include "include/PetriNetError.h"
#include <boost/log/trivial.hpp>

using namespace std;

int main(int argc, char* argv[]){
    const char* filename = "pn.xml";
//    PetriNetError er;
//    boost::system::error_code ec(14, er);
    PNMLParse xp;
    ReachGraph rg;
    rg.pn = xp.read(filename);
    BOOST_LOG_TRIVIAL(info) << "获取转移矩阵";
    rg.pn.getA();
    BOOST_LOG_TRIVIAL(info) << "构造可达树";
    rg.ReachabilityTree();
    system("pause");
    return 0;
}