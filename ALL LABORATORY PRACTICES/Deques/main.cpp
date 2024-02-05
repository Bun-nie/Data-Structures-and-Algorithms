#include<iostream>
#include"dequelist.h"
using namespace std;

int main(){
    char op;
    int num;
    DequeList* list = new DequeList();
    do {
        cout<<"Enter op: ";
        cin>>op;
        switch (op){
            case 'f':
                cin>>num;
                list->addFirst(num);
                break;
            case 'l':
                cin>>num;
                list->addLast(num);
                break;
            case 'F':
                cout<<"Removed "<<list->removeFirst()<<endl;
                break;
            case 'L':
                cout<<"Removed "<<list->removeLast()<<endl;
                break;
            case 's':
                cout<<"Size: "<<list->size()<<endl;
                break;
            case 'p':
                list->print();
                break;
            case '_':
                if(list->isEmpty()){
                    cout<<"Empty"<<endl;
                } else {
                    cout<<list->size()<<" element/s"<<endl;
                }
                break;
            case 'x':
                cout<<"Terminating Program..."<<endl;
                break;
            default:
                cout<<"Invalid Option"<<endl;
                break;
        }
    } while (op != 'x');
    return 0;
}