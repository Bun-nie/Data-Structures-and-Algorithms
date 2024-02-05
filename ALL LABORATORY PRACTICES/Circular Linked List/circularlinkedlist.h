#include<iostream>
#include"node.h"
#include"list.h"
using namespace std;

class CLL : public List {
    node* tail;
    int size;
public:
    CLL(){
        tail=NULL;
        size=0;
    }
    // BOGO NO HEAD CHALLANGE KINSA MN GA BUOT ANI WTF YAWA

    // void addFirst (int x) {
    //     node* n = new node;
    //     n->elem = x;
    //     if (size == 0) {
    //         head = n;
    //         tail = n;
    //     } else {
    //         tail->next = n;
    //         n->next = head;
    //         head = n;
    //     }
    //     size++;
    // }

    // void add (int x) {
    //     node* n = new node;
    //     n->elem = x;

    //     if (size == 0) {
    //         head = n;
    //         tail = n;
    //     } else {
    //         tail->next = n;
    //         n->next = head;
    //         tail = n;
    //     }
    //     size++;
    // }

    // void display () {
    //     node* cur = head;
    //     int ctr = 0;

    //     cout << "Size: " << size << endl;
    //     cout << "FROM HEAD: ";
    //     while (ctr != size) {
    //         cout << cur->elem << " ";
    //         cur = cur->next;
    //         ctr++;
    //     }
    //     cout << endl;
    // }

    // void rotate () {
    //     head = head->next;
    //     tail = tail->next;
    // }

    // int getTail () {
    //     return tail->elem;
    // }

    void addFirst(int num) {
        node* n = new node;
        n->elem = num;
        if (size==0) {
            tail = n;
            tail->next = n;
            size++;
            return;
        }
        node* head = tail->next;
        tail->next = n;
        n->next = head;
        size++;
    }

    void addLast(int num){
        node* n = new node;
        n->elem = num;
        if (size==0) {
            tail = n;
            tail->next = n;
            size++;
            return;
        }
        node* head = tail->next;
        tail->next = n;
        n->next = head;
        tail = n;
        size++;
    }

   void display() {
        // if(size==0){
        //     cout<<"Empty"<<endl;
        //     return;
        // }
        // node* cur = tail->next;
        // int ctr = 0;
        // cout << "SIZE: " << size << endl;
        // while (ctr <= size) {
        //     cout << cur->elem;
        //     if(ctr<size){
        //         cout<<"->";
        //     }
        //     cur = cur->next;
        //     ctr++;
        // }
        // cout << endl;
        cout << "Size: " << size << endl;
        // TODO implement printing of elements using rotate()
        if(size==0){
            cout<<"Empty"<<endl;
            return;
        }
        int ctr = 0;
        
        while (ctr <= size) {
            node* cur = tail->next;
            cout << cur->elem;
            if(ctr<size){
                cout<<"->";
                rotate();
            }
            ctr++;
        }
        cout << endl;
   }

   void rotate () {
        if(size==0){
            return;
        }
        tail = tail->next;
    }

    int removeFirst () {
        if(size==0){
            return -1;
        }
        node* temp = tail->next;
        int num = temp->elem;
        tail->next = temp->next;
        size--;
        free(temp);
        temp=NULL;
        return num;
    }
};

