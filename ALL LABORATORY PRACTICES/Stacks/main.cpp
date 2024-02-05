#include<iostream>
#include"stacklist.h"
using namespace std;

int main(){
    char op;
    int elem;
    int ret;
    Stack* stack = new ArrayStack();
    do {
        cout<<"Enter op: ";
        cin>>op;
        switch (op)
        {
        case '+':
            cin>>elem;
            stack->push(elem);
            break;
        case '*':
            ret = stack->pop();
            if(ret == -1){
                cout<<"No element to remove"<<endl;
            } else {
                cout<<"Removed "<<ret<<" from the top"<<endl;
            }
            break;
        case 't':
            cout<<"Element "<<stack->top()<<" is on top of the stack"<<endl;
            break;
        case 's':
            cout<<"Size: "<<stack->size()<<endl;
            break;;
        case 'e':
            if(stack->isEmpty()){
                cout<<"No elements in this stack"<<endl;
            } else {
                cout<<"This stack has "<<stack->size()<<" element/s"<<endl;
            }
            break;
        case 'f':
            if(stack->isFull()){
                cout<<"Stack Overflow!!!"<<endl;
            } else {
                cout<<"This stack has "<<(52-stack->size())<<" space/s left"<<endl;
            }
            break;
        case 'w':
            stack->wipeout();
            break;
        case 'p':
            stack->print();
            break;
        case 'x':
            cout<<"Terminating program..."<<endl;
            break;
        default:
            cout<<"Not a valid option!"<<endl;
            break;
        }
    } while (op != 'x');
    return 0;
}