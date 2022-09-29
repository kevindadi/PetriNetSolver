//
// Created by kevin on 22-9-29.
//

#ifndef PETRINETSOLVER_PETRINET_H
#define PETRINETSOLVER_PETRINET_H

#include <string>
#include <vector>
using namespace std;

struct Arc {
    string id;
    string source;
    string target;
    int sourceNum = 0;
    int sourceP = 0;
    int sourceT = 0;
    int targetNum = 0;
};

typedef struct PetriNetPlace {
    string name;
    int num = 0;
    int initialMarking = 0;
}Place;

typedef struct PetriNetTransition {
    string name;
    int num = 0;
}Transition;

class PetriNet {
public:
    vector<Place> place;
    vector<Transition> transition;
    vector<Arc> arc;
    PetriNet();
    ~PetriNet();

    void getA();

    // 关联矩阵
    int A[30][30];
    // 输入矩阵
    int A1[30][30];
    // 输出矩阵
    int A2[30][30];
};




#endif //PETRINETSOLVER_PETRINET_H
