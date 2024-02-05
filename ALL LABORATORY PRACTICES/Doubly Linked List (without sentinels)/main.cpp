#include<iostream>
#include"doublylinkedlist.h"
using namespace std;

int main(){
    DoublyLinkedList* list = new DoublyLinkedList();
    DoublyLinkedList* list2 = new DoublyLinkedList();
    list2->addHead(3);
    list2->addTail(4);
    list2->addTail(5);
    char op;
    int num, pos, left, right;

    do {
        cout<<"Enter op: ";
        cin>>op;
        switch (op){
            case 'h':
                cin>>num;
                list->addHead(num);
                break;
            case 't':
                cin>>num;
                list->addTail(num);
                break;
            case 'g':
                cin>>pos;
                if(list->get(pos)==-1){
                    cout<<"No element in that position"<<endl;
                } else {
                    cout<<"Element at position "<<pos<<" is "<<list->get(pos)<<endl;
                }
                break;
            case 'f':
                list->removeFirst();
                break;
            case 'l':
                list->removeLast();
                break;
            case 'r':
                cin>>num;
                if(list->remove(num)==-1){
                    cout<<"Number not found in the list"<<endl;
                } else {
                    cout<<num<<" removed at position "<<list->remove(num)<<endl;
                }
                break;
            case '+':
                list->combine(list2);
                break;
            case '=':
                cin>>num;
                cout<<"Removed "<<list->retain(num)<<" element/s"<<endl;
                break;
            case 'c':
                cin>>left>>right;
                cout<<"Removed "<<list->corner(left, right)<<" element/s"<<endl;
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid Operation"<<endl;
        }
    } while (op != 'x');
    
    return 0;
}