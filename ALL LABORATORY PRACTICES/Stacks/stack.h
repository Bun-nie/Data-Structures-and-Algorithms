#include<iostream>
#include<cstdlib>
using namespace std;

class Stack {
    public:
        virtual void push(int e) = 0;
        virtual int pop() = 0; //returns and removes last element
        virtual int top() = 0; //returns last element
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
        virtual bool isFull() = 0;
        virtual void wipeout() = 0; //deletes all element/s in the stack

        virtual void print() = 0;
};