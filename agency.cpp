//
// Created by nazanin akhtarian on 12/17/17.
//

#include "agency.h"


//ag_node* first;
agency::agency()
{
    first = 0;
    first2 = 0;
}
ag_node* agency::find(int input) {
    ag_node* r = first;
    if (input <= ag_count)
    {
        for (int i = 1; i < input; i++)
        {
            r = r->link;
        }
        return r;
    }
    else return 0;
}
void agency::offer(s_node* k)
{
    //ag_node* q;
        cout << "Choose the agency you want to add to: "<< endl;
        print();
        cin >> input;
        //q = find(input);
    for (int i = 0; i < find(input)->ag_srvs.size(); i++) {
        if (find(input)->ag_srvs[i] == k) {
            return;
        }
    }
        find(input)->ag_srvs.push_back(k);

}
void agency::add(string nm)
{
    ag_node* p;
    p = new ag_node();
    ag_count++;
    if (p == NULL)
    {
        return;
    }
    p->data = nm;
    p->link = first;
    first = p;

}
void agency::print2(ag_node* p)          //print the agency services
{
    for (int i = 0; i < (p->ag_srvs).size(); i++) {
        cout << i+1 << "-" << ((p->ag_srvs)[i])->service_name << endl;
    }

}
void agency::print()
{
    ag_node* p;
    p = first;
    int i{};
    while (p != NULL)
    {
        cout << 1+i << "-" << p->data << endl;
        p = p->link;
        i++;
    }
}
