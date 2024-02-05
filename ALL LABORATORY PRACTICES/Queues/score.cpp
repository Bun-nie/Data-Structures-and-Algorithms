#include<iostream>
#include"queuelist.h"
using namespace std;

Queue* passing_only(Queue* scores, int passing){
    Queue* bbq = new QueueList();
    int num;
    if(scores->isEmpty()){
        return bbq;
    }
    do{
        num = scores->dequeue();
        if(num >= passing){
            bbq->enqueue(num);
        }
        
    }while(!scores->isEmpty());

    return bbq;
}

int main(){
    Queue* q = new QueueList();
    int num, passing;

    do {
        cout<<"Enter score: ";
        cin>>num;
        if(num != 0){
            q->enqueue(num);
        }
    } while (num != 0);

    cout<<"Enter passing score: ";
    cin>>passing;

    Queue* q2 = passing_only(q, passing);

    cout<<"Passing scores: ";

    if(q2->isEmpty()){
        cout<<"(none)"<<endl;
        return 0;
    }

    while(!q2->isEmpty()){
        cout<<q2->dequeue()<<" ";
    }
    return 0;
}