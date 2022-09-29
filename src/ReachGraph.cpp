//
// Created by kevin on 22-9-29.
//

#include "../include/ReachGraph.h"
#include <iostream>
using namespace std;

void ReachGraph::ReachabilityTree() {
    node = 0;
    //可达图的第一个节点（一个节点：初始标识）
    for (int i = 0; i < pn.place.size(); i++) {
        M0[i] = pn.place[i].initialMarking;
        rgNode[0].m[i] = M0[i];
    }
    node++;
    //判断结点列表中还存在没有标记的节点
    int newNode;
    int exit;
    while (1) {
        for (int i = 0; i < node; i++) {
            exit = 0;
            if (rgNode[i].flag == 0) {//找到标识为新的节点
                exit = 1;
                newNode = i;
                break;
            }
        }
        if (exit != 1) {//不存在标识为新的节点
            break;
        }
        //任选标识为新的节点newNode，设为M
        for (int i = 0; i < pn.place.size(); i++) {
            M[i] = rgNode[newNode].m[i];
        }
        //标记这个节点
        rgNode[newNode].flag = 1;

        //if 在M下所有变迁都不能发生
        int enable;
        int enableNumber = 0;
        for (int i = 0; i < pn.transition.size(); i++) {//对于所有的变迁
            enable = -1;
            for (int j = 0; j < pn.place.size(); j++) {
                if (M[j] < pn.A2[i][j]) {//变迁ti不能发生
                    enable = 0;
                    break;
                }
            }
            //变迁从t0开始编号
            if (enable == -1) {//变迁ti可以发生
                rgNode[newNode].is_fire_able[enableNumber] = i;
                rgNode[newNode].enableNum++;
                enableNumber++;
            }
        }
        if (rgNode[newNode].enableNum == 0) {//如果变迁不能发生则跳出本次循环
            continue;
        }
        //对于每个在M下可发生的变迁
        for (int i = 0; i < rgNode[newNode].enableNum; i++) {
            //可发生变迁ti的编号i为hang
            //计算M1
            for (int j = 0; j < pn.place.size(); j++) {
                int hang = rgNode[newNode].is_fire_able[i];
                M1[j] = M[j] + pn.A[hang][j];
            }
            //if结点列表中出现过M1
            int repeated;
            int ii;
            int exist = 0;
            for (ii = 0; ii < node; ii++) {
                repeated = 1;
                for (int jj = 0; jj < pn.place.size(); jj++) {
                    if (M1[jj] != rgNode[ii].m[jj]) {
                        repeated = 0;
                        break;
                    }
                }
                //若结点列表出现过M1
                if (repeated == 1) {
                    exist = 1;
                    //ii是重复的节点的序号
                    PRGEdge pEdge;
                    pEdge = new RGEdge;
                    pEdge->next_edge = nullptr;
                    pEdge->t = rgNode[newNode].is_fire_able[i];
                    pEdge->target = ii;
                    RGNode *p;
                    p = &rgNode[newNode];
                    pEdge-> next_edge = p->firstEdge;
                    p->firstEdge = pEdge;
                    break;
                }
            }
            //若M1是没有出现过的新状态
            if (exist == 0) {
                //则引入新节点rgNode[graph.node]，即M1。
                for (int i = 0; i < pn.place.size(); i++) {
                    rgNode[node].m[i] = M1[i];
                }
                rgNode[node].flag = 0;
                rgNode[node].t = rgNode[newNode].is_fire_able[i];
                //并把新节点加到邻接表边表上
                //bug这部分的连接有问题
                RGNode *p;
                PRGEdge pEdge;
                pEdge = new RGEdge;
                pEdge->next_edge = nullptr;
                pEdge->t = rgNode[newNode].is_fire_able[i];
                pEdge->target = node;
                p = &rgNode[newNode];
                pEdge->next_edge = p->firstEdge;
                p->firstEdge = pEdge;
                node++;
            }
        }
    }
    //打印可达图
    cout << "可达图节点个数" << node << endl;
    for (int i = 0; i < node; i++) {
        cout << "M[" << i << "]" << "(";
        for (int j = 0; j < pn.place.size(); j++) {
            cout << rgNode[i].m[j] << " ";
        }
        cout << ")";
        PRGEdge p;
        p = rgNode[i].firstEdge;
        for (int k = 0; k < rgNode[i].enableNum; k++) {
            cout << "[t";
            cout << p->t;
            cout << "M";
            cout << p->target;
            cout << ",";
            p = p->next_edge;
        }
        cout << endl;
    }
}