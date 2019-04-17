//
// Created by nazanin akhtarian on 12/17/17.
//

#ifndef UNTITLED_S_NODE_H
#define UNTITLED_S_NODE_H
#include<string>
#include<vector>
#include "o_node.h"

using namespace std;

class s_node {
public:
    vector<o_node>s_list;
    string service_name;
    string customer_exp;
    string model;
    string price;
    string agency_exp;
    int ref;
    int tag;
    s_node* link;
    s_node* dlink;
    s_node* temp{NULL};  //if we want to add sub service
                         // for the next times, we need
                         // a last sub service that was added
};


#endif //UNTITLED_S_NODE_H
