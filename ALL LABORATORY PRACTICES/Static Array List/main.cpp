#include<iostream>
#include<cstdlib>
#include"arraylist.h"
using namespace std;
int main(){
    List *list=new ArrayList();
    char op;
    int num, pos;
    do{
        cout<<"Enter op: ";
        cin>>op;
        switch(op){
            case '+':
                cin>>num;
                list->add(num);
                break;
            case '@':
                cin>>num;
                cin>>pos;
                list->addAt(num, pos);
                break;
            case '-':
                cin>>num;
                cout<<num<<" removed at position "<<list->remove(num)<<endl;
                break;
            case 's':
                cout<<"Size: "<<list->size()<<endl;
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid option!"<<endl;
                break;
        }
    } while (op != 'x');
    
    return 0;
}