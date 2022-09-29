//
// Created by kevin on 22-9-29.
//


#include <iostream>
#include "../include/XmlParse.h"
#include "../include/ReachGraph.h"
using namespace std;

int main(int argc, char* argv[]){
    const char* filename = "doc.xml";
    XmlParse xp;
    ReachGraph rg;
    rg.pn = xp.read(filename);
    rg.pn.getA();
    rg.ReachabilityTree();
    system("pause");
    return 0;
}