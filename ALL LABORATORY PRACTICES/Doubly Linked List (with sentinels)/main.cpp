#include<iostream>
#include"doublylinkedlist.h"
using namespace std;

int main(){
    DLL *list = new DLL();
    char op;
    int num, pos;
    int flag;
    do{
        cout<<"Enter op: ";
        cin>>op;

        switch(op){
            case 'h':
                cin>>num;
                list->addHead(num);
                break;
            case 't':
                cin>>num;
                list->addTail(num);
                break;
            case '@':
                cin>>num>>pos;
                list->addAt(num, pos);
                break;
            case 'd': //remove
                cin>>num;
                cout<<"Removed at position "<<list->remove(num)<<endl;
                break;
            case 'r': //removeAt
                cin>>pos;
                cout<<"Removed "<<list->removeAt(pos)<<endl;
                break;
            case 'R':
                cin>>num;
                cout<<"Removed "<<list->removeAll(num)<<" element/s"<<endl;
                break;
            case 'f':
                list->removeFirst();
                break;
            case 'l':
                list->removeLast();
                break;
            case 'i':
                cin >> num;
                flag = list->insert(num);
                if(flag == 1){
                    cout<<"Element inserted from head"<<endl;
                } else {
                    cout<<"Element inserted from tail"<<endl;
                }
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Not a valid option. Kindly enter another one"<<endl;
        }
    } while (op != 'x');

    
    return 0;
}