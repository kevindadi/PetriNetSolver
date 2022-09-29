//
// Created by kevin on 22-9-29.
//

#include "../include/PetriNet.h"

void PetriNet::getA() {
    for (int i = 0; i < this->arc.size(); i++) {
        if (arc[i].sourceP == 1) {
            A[arc[i].targetNum][arc[i].sourceNum]--;
            A2[arc[i].targetNum][arc[i].sourceNum]++;//输入矩阵
        }

        if (arc[i].sourceT == 1) {
            A[arc[i].sourceNum][arc[i].targetNum]++;
            A1[arc[i].sourceNum][arc[i].targetNum]++;//输出矩阵
        }
    }
}