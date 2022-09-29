//
// Created by kevin on 22-9-29.
//

#ifndef PETRINETSOLVER_REACHGRAPH_H
#define PETRINETSOLVER_REACHGRAPH_H
#include <vector>
#include "PetriNet.h"

struct Node {
    // 标识
    int m[30] = {0};
    // new = 0, old = 1, point = 2
    int flag = 0;
    int is_fire_able[30] = {0};
    Node* parent;
    int t = 0;
};

typedef struct RGEdge {
    int t;
    int target;
    RGEdge* next_edge = nullptr;
}RGEdge, *PRGEdge;

typedef struct RGNode {
    int m[100];
    int flag = 0;
    int is_fire_able[100] = {0};
    int enableNum = 0;
    int t = 0;
    PRGEdge firstEdge;
}RGNode, *PRGNode;

class ReachGraph {
public:
    int node = 0;
    int edge = 0;
    std::vector<RGNode> rgNode;
    PetriNet pn;
    int M0[100] = {0};
    int M1[100]= {0};
    int M[100] = {0};
    void ReachabilityTree();
};


#endif //PETRINETSOLVER_REACHGRAPH_H
