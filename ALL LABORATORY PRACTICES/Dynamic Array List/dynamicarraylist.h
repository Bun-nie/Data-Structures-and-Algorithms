#include <iostream>
#include<cstdlib>
#include "list.h"
using namespace std;

class DArrayList : public List {
    int *array;
    int size;
    int capacity=5;

    public:
    DArrayList() {
        array=(int*)malloc(sizeof(int)*capacity);
        size=0;
    }

    void add(int num) {
        if (size < capacity) {
            array[size++] = num;
        } else {
            capacity *= 1.5;
            array=(int*)realloc(array, sizeof(int)*capacity);
            array[size++] = num;
        }
    }

    void addFirst(int num){
        if(size==0){
            array[size]=num;
            size++;
            return;
        }
        for(int i=size;i>=0;i--){
            array[i]=array[i-1];
        }
        array[0]=num;
        size++;
    } 

    int remove(int num) {
        // Step 1: FIND the num
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                // Step 2: MOVE the elements to left
                for (int j = i; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                // Step 3: Set the size
                array[size-1] = 0;
                size = size-1;
                if((size<=0.67*capacity) && (capacity > 5)){
                    capacity *= 0.75;
                    if(capacity<5)
                        capacity=5;
                    array=(int*)realloc(array, sizeof(int)*capacity);
                }
                // Step 4: Return
                return i+1;
            }
        }
        return -1;
    }

    int get(int pos) {
        return array[pos-1];
    }

    
    void addAt(int num, int pos){
        pos = pos - 1;
        if(size < capacity){
            for(int i=size-1;i>=pos;i--){
                array[i+1]=array[i];
            }
            array[pos]=num;
            size++;
        } else {
            capacity *= 1.5;
            array=(int*)realloc(array, sizeof(int)*capacity);
            for(int i=size-1;i>=pos;i--){
                array[i+1]=array[i];
            }
            array[pos]=num;
            size++;
        }
    }

    int removeAt(int pos){
        int i=pos-1;
        int elem=array[i];
        for(int j=i;j<size;j++){
            array[j]=array[j+1];
        }
        array[--size]=0;
        if((size<=0.67*capacity) && (capacity > 5)){
            capacity *= 0.75;
            if(capacity<5)
                capacity=5;
            array=(int*)realloc(array, sizeof(int)*capacity);
        }
        return elem;
    }
    int removeFirst(){
        int elem = array[0];
        for(int i=0;i<size;i++){
            array[i]=array[i+1];
        }
        array[--size]=0;
        return elem;
    }

    int removeAll(int num){
        int count=0;
        for(int i=size-1;i>=0;i--){
            if(array[i]==num){
                count++;
                for(int j=i;j<size-1;j++){
                    array[j]=array[j+1];
                }
                array[--size]=0;
            }
        }
        if((size<=0.67*capacity) && (capacity > 5)){
            capacity *= 0.75;
            if(capacity<5)
                capacity=5;
            array=(int*)realloc(array, sizeof(int)*capacity);
        }
        return count;
    }
    

    void flip(){
        int temp;
        for(int i=0;i<(size/2);i++){
            temp=array[i];
            array[i]=array[size-i-1];
            array[size-i-1]=temp;
        }
    }


    void plus(int term){
        for(int i=0;i<size;i++){
            array[i]+=term;
        }
    }
    int summation(){
        int sum=0;
        for(int i=0;i<size;i++){
            sum+=array[i];
        }
        return sum;
    }

    int getSize(){
        return size;
    }

    void print() {
        cout<<"Capacity = "<<capacity<<endl;
        if(size==0){
            cout<<"Empty"<<endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};