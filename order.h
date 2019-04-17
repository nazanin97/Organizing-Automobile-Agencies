//
// Created by nazanin akhtarian on 12/18/17.
//

#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H

#include "o_node.h"
#include<iostream>
#include <vector>
#include "s_node.h"

class order {
public:
    void add(string nm,s_node* s);
    vector<o_node>human;
    void print(s_node* s);

};


#endif //UNTITLED_ORDER_H
