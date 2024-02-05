#include"deque.h"
//#include"C:/Users/Nicole Ejares/OneDrive/Documents/COLLEGE/Sophomor 1st Semester SY 2023-2024/CSIT221-Data Structures and Algorithms/ALL LABORATORY PRACTICE/Dynamic Array List/dynamicarraylist.h"
#include"C:/Users/Nicole Ejares/OneDrive/Documents/COLLEGE/Sophomor 1st Semester SY 2023-2024/CSIT221-Data Structures and Algorithms/ALL LABORATORY PRACTICE/Circular Array List/circulararraylist.h"
//^^This is circulararraylist.h^^
#include<iostream>
using namespace std;

class DequeList : public Deque {
    CArrayList* array;
    public:
        DequeList(){
            array = new CArrayList();
        }
        void addFirst(int e){
            array->addFirst(e);
        }
        void addLast(int e){
            array->addLast(e);
        }
        int removeFirst(){
            if(isEmpty()){
                return 0;
            }
            return array->removeFirst();
        }
        int removeLast(){
            if(isEmpty()){
                return 0;
            }
            return array->removeLast();
        }
        int size(){
            return array->getSize();
        }
        bool isEmpty(){
            if(size()==0){
                return true;
            } else {
                return false;
            }
        }
        void print(){
            array->print();
        }
};