#include"queue.h"
#include"C:/Users/Nicole Ejares/OneDrive/Documents/COLLEGE/Sophomor 1st Semester SY 2023-2024/CSIT221-Data Structures and Algorithms/ALL LABORATORY PRACTICE/Dynamic Array List/dynamicarraylist.h"
//^^This is dynamic arraylist.h^^
//#include"C:/Users/Nicole Ejares/OneDrive/Documents/COLLEGE/Sophomor 1st Semester SY 2023-2024/CSIT221-Data Structures and Algorithms/ALL LABORATORY PRACTICE/Singly Linked List/linkedlist.h"

class QueueList : public Queue {
    DArrayList* array;
    //LinkedList* list;
    public:
        //Using Arraylist
        QueueList(){
            array = new DArrayList();
        }
        void enqueue(int e){
            array->add(e);
        }
        int dequeue(){
            if(isEmpty()){
                return -1;
            }
            return array->removeFirst();
        }
        int peek(){
            if(isEmpty()){
                return -1;
            }
            return array->get(1);
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
        void reverse(){
            array->flip();
        }
        void print(){
            array->print();
        }

        //Using Singly  Linked List
        /*QueueList(){
            list = new LinkedList();
        }
        void enqueue(int e){
            list->addTail(e);
        }
        int dequeue(){
            if(isEmpty()){
                return -1;
            }
            return list->removeHead();
        }
        int peek(){
            if(isEmpty()){
                return -1;
            }
            return list->getHead();
        }
        int size(){
            return list->getSize();
        }
        bool isEmpty(){
            if(size()==0){
                return true;
            } else {
                return false;
            }
        }
        void reverse(){
            list->flip();
        }
        void print(){
            list->print();
        }*/
};