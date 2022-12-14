//
// Created by kevin on 22-9-29.
//

#ifndef PETRINETSOLVER_XMLPARSE_H
#define PETRINETSOLVER_XMLPARSE_H

#include "tinyxml2.h"
#include <string>
#include "../include/PetriNet.h"

using namespace std;
using namespace tinyxml2;

class XmlParse {
public:
    XmlParse();
    virtual ~XmlParse();

    string name;
    virtual PetriNet read(const char* filename);

    __attribute__((unused)) virtual void write();
};

class PNMLParse : public XmlParse {
public:
    PNMLParse();
    ~PNMLParse() override;

    PetriNet read(const char* filename) override;
    void write() override;
private:
    string path;
};


#endif //PETRINETSOLVER_XMLPARSE_H
