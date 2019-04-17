//
// Created by nazanin akhtarian on 12/17/17.
//

#ifndef UNTITLED_AG_NODE_H
#define UNTITLED_AG_NODE_H

#include <string>
#include<vector>
#include "s_node.h"

using namespace std;

class ag_node {
public:
    vector<s_node*>ag_srvs;
    string data;
    ag_node* link;
    ag_node* dlink;
};


#endif //UNTITLED_AG_NODE_H
