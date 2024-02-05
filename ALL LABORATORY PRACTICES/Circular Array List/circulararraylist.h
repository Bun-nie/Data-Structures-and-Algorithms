#include<iostream>
#include"circularlist.h"
using namespace std;
#define SIZE 10

class CArrayList : public CArray {
    int size, first, last;
    int array[SIZE];

    public:
    CArrayList(){
        size = 0;
        first = -1;
        last = -1;
    }
    void addFirst(int num){
        if((last+1)%SIZE == first){
            cout<<"PUNO NA"<<endl;
            return;
        } else {
            if(first == -1){
                first = 0;
                last = (last+1) % SIZE;
                array[first] = num;
                size++;
                return;
            } else {
                first = (first - 1 + SIZE) % SIZE;
                array[first]=num;
                size++;
            }
        }
    }
    void addLast(int num){
        if((last+1)%SIZE == first){
            cout<<"PUNO NA"<<endl;
            return;
        } else {
            if(first == -1){
                first = 0;
            }
            last = (last+1) % SIZE;
            array[last] = num;
            size++;
        }
    }
    int removeFirst(){
        if(isEmpty()){
            cout<<"No elements"<<endl;
            return 0;
        }
        int num = array[first];
        if(first == last){
            first = last = -1;
        } else {
            first = (first + 1)%SIZE;
        }
        size--;
        return num;
    }
    int removeLast(){
        if(isEmpty()){
            cout<<"No elements"<<endl;
            return 0;
        }
        int num = array[last];
        if(first == last){
            first = last = -1;
        } else {
            last = (last - 1 + SIZE) % SIZE;
        }
        size--;
        return num;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        if(first == -1 && last == -1){
            return true;
        } else {
            return false;
        }
    }
    void print(){
        if(isEmpty()){
            cout<<"No elements"<<endl;
            return;
        }
        cout<<"First Index: "<<first<<endl;
        cout<<"Last Index: "<<last<<endl;
        for(int i=0;i<SIZE;i++){
            if(i>last && i<first){
                cout<<"? ";
                continue;
            }
            cout<<array[i]<<" ";
        }

        cout<<endl;
    }
};