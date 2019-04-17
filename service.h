//
// Created by nazanin akhtarian on 12/17/17.
//

#ifndef UNTITLED_SERVICE_H
#define UNTITLED_SERVICE_H

#include "s_node.h"
#include<iostream>

class service {
public:
    s_node* first;
    s_node* first2;
    int s_count;                //number of services
    string service_name;       //nm
    string customer_exp;       //ce
    string model;              //mdl
    string price;              //pr
    string agency_exp;
    service();
    s_node* find(int inp);
    void set_ref(s_node* s);
    void deleting(int n);                                                    //delete service
    void setting(s_node* p);
    void tagging(int t);                                                        //tag=1 if service have sub services
    void sub(int inp);
    void add(string nm,string mdl, string ce, string ae, string pr);           //add service
    s_node* addsub(string nm,string mdl, string ce, string ae, string pr);     //add sub service
    void print();
};


#endif //UNTITLED_SERVICE_H
