//
// Created by nazanin akhtarian on 12/17/17.
//

#include "service.h"

service::service()
{
    first = 0;
    first2 = 0;
}
s_node* service::find(int inp) {
    s_node *p;
    p = first;
    if (inp <= s_count)
    {
        for (int i = 1; i < inp; i++)
        {
            p = p->link;
        }
        return p;
    }
    else return 0;
}
void service::set_ref(s_node* s)
{
    (s->ref)++;
}
void service::setting(s_node* p)
{
    first2 = p->temp;
}

void service::tagging(int t)
{
    if (t<=s_count)
    {
        s_node* p;
        p = first;
        for (int i = 1; i < t; i++)
        {
            p = p->link;
        }
        p->tag = 1;
    }
}

void service::sub(int inp)
{
    s_node* p;
    p = first;
    char name2;   //add more or not
    if (inp <= s_count) {
        for (int i = 1; i < inp; i++)
        {
            p = p->link;
        }
        setting(p);
        do {
            cout << "Enter your sub service name and properties:" << endl;
            cin >>  service_name >> model >> customer_exp >> agency_exp >> price;
            p->dlink = addsub(service_name,model,customer_exp,agency_exp,price);
            cout << "want to add more?\nEnter y or n" << endl;
            cin >> name2;
            p->temp=first2;
        } while (name2 == 'y');
    }
    else
        cout << "no service!" << endl;
}

s_node* service::addsub(string nm,string mdl, string ce, string ae, string pr)
{
    s_node* p;
    p = new s_node;
    p->service_name = nm;
    p->customer_exp = ce;
    p->model = mdl;
    p->price = pr;
    p->agency_exp = ae;
    p->link = first2;
    first2 = p;
    return p;
}

void service::add(string nm,string mdl, string ce, string ae, string pr)
{
    s_node* p;
    p = new s_node;
    s_count++;
    if (p == NULL)
    {
        return;
    }
    p->service_name = nm;
    p->customer_exp = ce;
    p->model = mdl;
    p->price = pr;
    p->agency_exp = ae;
    p->link = first;
    first = p;
}

void service::deleting(int n)
{
    if(n==1)
    {
        first = find(2);
    }
    if(n == s_count)
        {
            find(n-1)->link=0;
        }
    else {
        find(n - 1)->link = find(n + 1);
    }
     s_count--;
}

void service::print()
{
    s_node* p;
    p = first;
    s_node* q=p;      //to save p->link when we want to print sublist(p->dlink)

    int i{1};
    while (p != NULL || q!=NULL)
    {
        p=q;
        if (p->tag == 0)
        {
            cout << i << "-";
            cout << p->service_name << endl;
            i++;
            p = p->link;
            q=p;
        }

        else
        {
            cout << i << "-";
            cout << p->service_name << endl;
            i++;
            q=p->link;
            p=p->dlink;
            do{
                cout << "   ";
                cout << p->service_name << endl;
                p=p->link;
            }while(p!=NULL);
        }
    }
}
