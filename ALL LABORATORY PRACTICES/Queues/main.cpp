#include<iostream>
#include"queuelist.h"
using namespace std;
int main(){
    QueueList* queue = new QueueList();
    char op;
    int num;
    do {
        cout<<"Enter option: ";
        cin>>op;
        switch (op){
        case 'e':
            cin>>num;
            queue->enqueue(num);
            break;
        case 'd':
            cout<<"Removed "<<queue->dequeue()<<endl;
            break;
        case 'f':
            cout<<"Element first in line is "<<queue->peek()<<endl;
            break;
        case 's':
            cout<<"Size: "<<queue->size()<<endl;
            break;
        case '_':
            if(queue->isEmpty()){
                cout<<"No element in queue"<<endl;
            } else {
                cout<<queue->size()<<" element/s in queue"<<endl;
            }
            break;
        case 'p':
            queue->print();
            break;
        case 'r':
            queue->reverse();
            break;
        case 'x':
            cout<<"Terminating program..."<<endl;
            break;
        default:
            cout<<"Not a valid option"<<endl;
            break;
        }
    } while (op != 'x');
    return 0;
}