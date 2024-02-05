#include<iostream>
#include"arrayheap.h"
using namespace std;

int main(){
    ArrayHeap* heap = new ArrayHeap();
    int num;
    char op;
    do {
        cout<<"Enter op: ";
        cin>>op;
        switch (op){
        case 'i': //insert
            cin>>num;
            heap->insert(num);
            break;
        case 'r': //remove a number input by user
            cin>>num;
            cout<<"Removed "<<num<<" from position "<<heap->remove(num);
            break;
        case 'm': //remove largest number in the heap (max_)
            cout<<"Removed "<<heap->removeMax()<<" from root"<<endl;
            break;
        case '?': //search for an element
            cin>>num;
            cout<<num<<" found at position "<<heap->search(num)<<endl;
            break;
        case 's': //size
            cout<<"Size of the heap: "<<heap->getSize()<<endl;
            break;
        case 'p': //print
            heap->print();
            break;
        case 'x':
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Invalid option"<<endl;
            break;
        }
    } while (op != 'x');
    return 0;
}