//
// Created by kevin on 22-9-29.
//

#include "../include/XmlParse.h"
#include <iostream>


PetriNet PNMLParse::read(const char* filename) {
    int m = 0, n =0, arcNum = 0;
    auto result = PetriNet();
    XMLDocument doc;
    auto loadOk = doc.LoadFile(filename);
    if (!loadOk) {
        std::cout << "加载文件失败" << std::endl;
        exit(1);
    }

    XMLElement *pnmlElement = doc.RootElement();
    XMLElement *netElement = pnmlElement->FirstChildElement("net");
//    XMLElement *pageElement = netElement->FirstChildElement("page");

    for (XMLElement *petriElement = netElement->FirstChildElement();
        petriElement;
        petriElement = petriElement->NextSiblingElement()){
        Place p;
        Transition t;
        Arc arc;
        if (petriElement->Value() == "place") {
//            result.place[m].num = m;
            p.num = m;
            if (petriElement->FirstChildElement("initialMarking")) {
                XMLElement* initialMarkingElement = petriElement->FirstChildElement("initialMarking")->FirstChildElement("value");
//                result.place[m].initialMarking = atoi(initialMarkingElement->GetText());
                p.initialMarking = atoi(initialMarkingElement->GetText());
            }
            XMLElement* nameElement = petriElement->FirstChildElement("name")->FirstChildElement("value");
            p.name = nameElement->GetText();
            m++;
            result.place.push_back(p);
        }

        if (petriElement->Value() == "transition") {
            t.num = n;
            XMLElement *tNameElement = petriElement->FirstChildElement("name")->FirstChildElement("value");
            t.name = tNameElement->GetText();
            n++;
            result.transition.push_back(t);
        }
        if (petriElement->Value() == "arc") {
            auto* arcAttr = const_cast<XMLAttribute *>(petriElement->FirstAttribute());
            arc.id = arcAttr->Value();
            arcAttr = const_cast<XMLAttribute *>(arcAttr->Next());
            arc.source = arcAttr->Value();
            arcAttr = const_cast<XMLAttribute *>(arcAttr->Next());
            arc.target = arcAttr->Value();
            arcNum++;
            result.arc.push_back(arc);
        }
    }

    for (int i = 0; i < arcNum; i++){
        for (int j = 0; j < n; ++j) {
            if (result.arc[i].source == result.transition[j].name){
                result.arc[i].sourceT = 1;
                result.arc[i].sourceNum = result.transition[j].num;
            }
            if (result.arc[i].target == result.transition[j].name){
                result.arc[i].targetNum = j;
            }
        }
        for (int k = 0; k < m; k++) {//和库所比
            if (result.arc[i].source == result.place[k].name) {
                result.arc[i].sourceP = 1;
                result.arc[i].sourceNum = result.place[k].num;
            }
            if (result.arc[i].target.compare(result.place[k].name) == 0) {
                result.arc[i].targetNum = k;
            }
        }
    }

    return result;
}

void PNMLParse::write() {
    std::cout << "不会写了" << std::endl;
}

PNMLParse::~PNMLParse(){
    std::cout << "忍不住赋诗一首" << std::endl;
}

PNMLParse::PNMLParse() = default;

XmlParse::XmlParse() = default;

XmlParse::~XmlParse() = default;

PetriNet XmlParse::read(const char *filename) {
    return PetriNet();
}

void XmlParse::write() {

}
