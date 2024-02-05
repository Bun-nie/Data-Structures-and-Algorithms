#include"stack.h"
//#include"C:/Users/Nicole Ejares/OneDrive/Documents/COLLEGE/Sophomor 1st Semester SY 2023-2024/CSIT221-Data Structures and Algorithms/ALL LABORATORY PRACTICE/Dynamic Array List/dynamicarraylist.h"
#include"C:/Users/Nicole Ejares/OneDrive/Documents/COLLEGE/Sophomor 1st Semester SY 2023-2024/CSIT221-Data Structures and Algorithms/ALL LABORATORY PRACTICE/Singly Linked List/linkedlist.h"


class ArrayStack : public Stack {
    LinkedList* array;
    public:
        //Using Arraylist
        /*ArrayStack(){
            array = new DArrayList();
        }
        void push(int e){
            array->add(e);
        }
        int pop(){
            if(size()==0){
                return -1;
            }
            int num = array->removeAt(size());
            return num;
        }
        int top(){
            if(size()==0){
                return -1;
            }
            return array->get(size());
        }
        int size(){
            return array->getSize();
        }
        bool isEmpty(){
             if(size() == 0){
                return true;
             } else {
                return false;
             }
        }
        bool isFull(){
            if(size() > 52){
                return true;
            } else {
                return false;
            }
        }
        void wipeout(){
            int last = size();
            for(int i=0;i<last;i++){
                pop();
            }
            cout<<"Wipeout Complete"<<endl;
        }
        void print(){
            array->print();
        }*/

        //Using Linked List
        ArrayStack(){
            array = new LinkedList();
        }
        void push(int e){
            array->addHead(e);
        }
        int pop(){
            if(size()==0){
                return -1;
            }
            int num = array->removeHead();
            return num;
        }
        int top(){
            if(size()==0){
                return -1;
            }
            return array->getHead();
        }
        int size(){
            return array->getSize();
        }
        bool isEmpty(){
             if(size() == 0){
                return true;
             } else {
                return false;
             }
        }
        bool isFull(){
            if(size() > 52){
                return true;
            } else {
                return false;
            }
        }
        void wipeout(){
            int last = size();
            for(int i=0;i<last;i++){
                pop();
            }
            cout<<"Wipeout Complete"<<endl;
        }
        
        void print(){
            array->print();
        }
};