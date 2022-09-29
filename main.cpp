//
// Created by kevin on 22-9-29.
//


#include <iostream>
#include "XmlParse.h"
#include "ReachGraph.h"
using namespace std;

int main(int argc, char* argv[]){
    const char* filename = "pn.xml";
    PNMLParse xp;
    ReachGraph rg;
    rg.pn = xp.read(filename);
    rg.pn.getA();
    rg.ReachabilityTree();
    system("pause");
    return 0;
}