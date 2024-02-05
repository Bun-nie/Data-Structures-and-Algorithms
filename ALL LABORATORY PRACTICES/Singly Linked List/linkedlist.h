#include<iostream>
#include"list.h"
#include"node.h"
using namespace std;

class LinkedList : public List {
    int size;
    node *head, *tail;

    public:
    LinkedList(){
        size = 0;
        head = NULL;
        tail = NULL;
    }
    int getSize(){
        return size;
    }
    void add(int num) {
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		if (size == 0) {
			head = n;
			tail = n;
		} else {
			tail->next = n;
			tail = n;
		}
		size++;
	}
    void addHead(int num){
        node* n = new node;
        n->elem = num;
        n->next = head;
        head = n;
        if(tail==NULL){
            tail = n;
        }
        size++;
    }
    void addTail(int num){
        add(num);
    }
    int get(int pos){
        node *cur = head;
        int index=1;
        while (index != pos){
            cur = cur->next;
            index++;
        }
        return cur->elem;
    }
    int getHead(){
        return head->elem;
    }
    int remove(int num){
        node* cur = head;
    	node* temp;
        int index = 1;
    	while (cur) {
    		if (cur->elem == num) {
                if (cur == head) {
                    head = head->next;
                } else {
        			temp->next = cur->next;
                }
                free(cur);
    			size--;
    			return index;
			}
			temp = cur;
			cur = cur->next;
    		index++;
		}
        return -1;
    }
    int removeAt(int pos){
        int index=1;
        node *cur=head;
        node *temp;
        while (index <= pos){
            if(index==pos){
                int num = cur->elem;
                if(cur==head){
                    head=cur->next;
                } else {
                    temp->next=cur->next;
                }
                free(cur);
                size--;
                return num;
            }
            temp=cur;
            cur=cur->next;
            index++;
            }   
        return -1;
    }
    void addAt(int num, int pos) {
        node *n = new node;
        node *cur = head;
        if(pos==1){
            addHead(num);
            return;
        } else if (pos>size){
            addTail(num);
            return;
        } else {
            for(int i=1;i<pos-1;i++){
                cur=cur->next;
            }
            n->elem=num;
            n->next=cur->next;
            cur->next=n;
            size++;
        }
        
    }
    int removeAll(int num) {
        int index = 0;
        node *cur, *temp;
        cur=head;
        for(int i=1;i<=size;i++){
            if(cur->elem==num){
                if(cur==head){
                    head=cur->next;
                    free(cur);
                    cur=head;
                } else {
                    temp->next=cur->next;
                    free(cur);
                    if(i==size){
                        tail=temp;
                    }
                    cur=temp->next;
                }
            index++;
            size--;
            i--;
            } else {
                temp=cur;
                cur=cur->next;
            }
        }
        return index;
    }
    int removeHead(){
        node* temp = head;
        int num = temp->elem;
        head = head->next;
        free(temp);
        temp=NULL;
        size--;
        return num;
    }
    void flip(){
        node* cur = head;
        node* prev = NULL;
        node* temp = NULL;

        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head = prev;
        cur = head;
        while(cur->next){
            cur = cur->next;
        }
        tail = cur;
    }
    void print(){
        node* cur = head;
        cout<<"Size = "<<size<<endl;
        if(size==0)
            return;
        cout<<"For checking, Head: "<<head->elem<<", Tail: "<<tail->elem<<endl;
        while (cur != NULL) {
            cout<<cur->elem<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};