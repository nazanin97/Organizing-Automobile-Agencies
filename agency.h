//
// Created by nazanin akhtarian on 12/17/17.
//

#ifndef UNTITLED_AGENCY_H
#define UNTITLED_AGENCY_H

#include <string>
#include "ag_node.h"
#include<iostream>

using namespace std;

class agency {
public:
    void add(string nm);
    void offer(s_node* p);
    ag_node* first;
    ag_node* first2;
    char in;
    int input;
    agency();
    void print();
    void print2(ag_node* p);
    ag_node* find(int inp);
    int ag_count;

};


#endif //UNTITLED_AGENCY_H
