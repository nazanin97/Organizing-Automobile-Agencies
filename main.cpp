
#include<iostream>
#include"agency.h"
#include "service.h"
#include "order.h"

using namespace std;

int main()
{
    bool u;    //continue or not
    string name1;
    char name2;
    int input;
    int input2;
    string nam;
    string mod;
    string cex;
    string aex;
    string pri;

    service srv;
    agency ag;
    order odr;

    //defining some services
    srv.add("warranty","renult","cexp1","aexp1","100");
    srv.add("engine_oil", "maxima", "cexp2", "aexp2", "200");
    srv.add("color", "206", "cexp3", "aexp3", "140");
    srv.add("ring", "bmw", "cexp4", "aexp4", "500");
    ag.add("north");
    ag.add("south");
    ag.add("west");
    ag.add("east");

    do
    {
        cout << "*****************************************************************************" << endl;
        cout << "1-Add Agency" << endl;
        cout << "2-Agency List" << endl;
        cout << "3-Services List" << endl;
        cout << "4-Add Service" << endl;
        cout << "5-Add Sub Service" << endl;
        cout << "6-Offer Service to Agency" << endl;
        cout << "7-Agency's Services" << endl;
        cout << "8-Delete Service from Agency" << endl;
        cout << "9-Order" << endl;
        cout << "10-Order list" << endl;
        cout << "Enter your number: " << endl;

        cin >> input;
        switch (input)
        {
            case 1:
            {
                do {
                    //system("CLS");
                    cout << "Enter your agency name:" << endl;
                    cin >> name1;
                    ag.add(name1);
                    cout << "want to add more?\n(Enter y or n)" << endl;
                    cin >> name2;
                } while (name2 == 'y');
                //system("CLS");
                break;
            }

            case 2:
            {
                //system("CLS");
                cout << "Agency List:\n" << endl;
                ag.print();
                cout << endl;
                break;
            }
            case 3:
            {
                //system("CLS");
                cout << "Services List:\n" << endl;
                srv.print();
                cout << endl;
                break;
            }
            case 4:
            {
                do {
                    //system("CLS");
                    cout << "Enter your service name and properties:" << endl;
                    cin >> nam >> mod >> cex >> aex >> pri;
                    srv.add(nam, mod, cex, aex, pri);
                    cout << "want to add more?\nEnter y or n" << endl;
                    cin >> name2;
                } while (name2 == 'y');
                break;
            }
            case 5:
            {
                cout << "Enter your service number:" << endl;
                srv.print();
                cout << "\n>> ";
                cin >> input2;
                srv.tagging(input2);
                srv.sub(input2);
                break;

            }
            case 6:
            {
                cout << "Choose the service: " <<endl;
                srv.print();
                cout << ">> ";
                cin >> input2;
                srv.set_ref(srv.find(input2));
                ag.offer(srv.find(input2));
                break;
            }
            case 7:
            {
                cout<<"Choose the Agency"<<endl;
                ag.print();
                cin>>input2;
                cout<< "services:" <<endl;
                ag.print2(ag.find(input2));
                break;
            }
            case 8:
            {

                cout<<"Choose the Agency"<<endl;
                ag.print();
                cin>>input2;
                ag_node* tmp;
                tmp=ag.find(input2);             //tmp is an ag_node*
                cout <<"Choose the service you want to delete from this agency: " << endl;
                ag.print2(tmp);
                cout << "services?!(y or n)"<< endl;
                cin >> name2;
                if(name2 == 'n')
                    break;
                cout << "Choose your number : ";
                cin >> input2;
                tmp->ag_srvs[input2-1]->ref--;
                (ag.find(input2)->ag_srvs).erase((ag.find(input2)->ag_srvs).begin() + input2-1);
                if(tmp->ag_srvs[input2-1]->ref == 0)
                {
                    srv.deleting(input2);
                }
                break;
            }
            case 9:
            {
                cout<<"Choose the Agency"<<endl;
                ag.print();
                cin >>input2;
                //cout << endl;
                ag_node* tmp;
                tmp=ag.find(input2);
                ag.print2(tmp);
               cout << "\nservices?!(y or n)"<< endl;
                cin >> name2;
                if(name2 == 'n')
                    break;
                cout << "Choose your number : ";
                cin >> input2;
                cout << "Enter your name : ";
                cin >> name1;
                odr.add(name1,srv.find(input2));
                break;
            }
            case 10:
            {
                cout<<"Choose the Agency: "<<endl;
                ag.print();
                cin >>input2;
                cout << endl;
                ag_node* tmp;
                tmp=ag.find(input2);
                ag.print2(tmp);
                cout << "services?!(y or n)"<< endl;
                cin >> name2;
                if(name2 == 'n')
                    break;
                cout << "Choose your number: ";
                cin >> input2;
                odr.print(srv.find(input2));

                break;
            }
            default:
            {
                //system("CLS");
                cout << "Enter correct number!" << endl;
                break;
            }
        }
        cout << "continue?(y or n) ";
        cin >> name2;
        if (name2 == 'y')
        {
            u = true;
            //system("ClS");
        }
        else
            u = false;
    } while (u);

    return 0;
}