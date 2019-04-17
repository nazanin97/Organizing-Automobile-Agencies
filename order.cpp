//
// Created by nazanin akhtarian on 12/18/17.
//

#include "order.h"

void order::add(string nm,s_node* s) {

    o_node o;
    o.name=nm;
    cout << "\nEnter immediately level : " << endl;
    cout << "1-normal" <<endl;
    cout << "2-needful" <<endl;
    cout << "3-emergency" <<endl;
    int input;
    cin >> input;
    o.i_level=input;
    s->s_list.push_back(o);


}
void order::print(s_node* s)
{
    vector<o_node>normal;
    vector<o_node>needful;
    vector<o_node>emergency;

    for (int i = 0; i < s->s_list.size(); i++) {
        if(s->s_list[i].i_level==3)
        {
            emergency.push_back(s->s_list[i]);
        }
        else if(s->s_list[i].i_level==2)
        {
            needful.push_back(s->s_list[i]);
        }
        else if(s->s_list[i].i_level==1)
        {
            normal.push_back(s->s_list[i]);
        }
    }
    for (int j = 0; j < emergency.size(); j++) {
        cout << emergency[j].name << endl;
    }
    for (int j = 0; j < needful.size(); j++) {
        cout << needful[j].name << endl;
    }
    for (int j = 0; j < normal.size(); j++) {
        cout << normal[j].name << endl;
    }
}