#include<iostream>
#include"list.h"
#include"node.h"
using namespace std;

class DoublyLinkedList : public List {
    int size;
    node* head;
    node* tail;
    public:
        DoublyLinkedList(){
            size = 0;
            head=NULL;
            tail=NULL;
        }
        void addHead(int num){
            node* n = (node*)calloc(1, sizeof(node));
            n->elem = num;
            n->prev = NULL;
            if(size==0){
                head = n;
                tail = n;
                n->next=NULL;
            } else {
                n->next = head;
                head->prev = n;
                head = n;
            }
            size++;
        }
        void addTail(int num){
            node* n = (node*)calloc(1, sizeof(node));
            n->elem = num;
            n->next = NULL;
            if(size==0){
                head = n;
                tail = n;
                n->prev=NULL;
            } else {
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
            size++;
        }
        int get(int pos){
            if(pos<=0 || pos>size || size==0){
                return -1;
            }

            node* cur1 = head;
            node* cur2 = tail;
            int index1 = 1;
            int index2 = size;
            int num = 0;
            
            while (index1 <= pos || index2 >= pos){
                if(index1 == pos){
                    num = cur1->elem;
                    return num;
                } else if (index2 == pos){
                    num = cur2->elem;
                    return num;
                }
                cur1 = cur1->next;
                cur2 = cur2->prev;
                index1++;
                index2--;
            }
            return -1;
        }
        //get
            /*node* curr;
            int ctr = 1;
            if (pos <= 0 || pos > size){
                return -1;
            }
            if (pos <= ceil (size/2.0)) {
                cout << "From head, number of comparisons: " << pos << endl;
                curr = head;
                while (ctr != pos) {
                    curr = curr->next;
                    ctr++;
                }
                //return curr -> elem;
            } else {
                cout << "From tail, number of comparisons: " << size - pos + 1 << endl;
                curr = tail;
                ctr = size;
                while (ctr > pos) {
                    curr = curr->prev;
                    ctr--;
                }
            }

            return curr -> elem;
        */
        void removeFirst(){
            if(size==0){
                cout<<"No element"<<endl;
                return;
            }
            head=head->next;
            if(head){
                free(head->prev);
                head->prev=NULL;
            } else {
                free(tail);
                tail=NULL;
            }
            size--;
        }
        void removeLast(){
            if(size==0){
                cout<<"No element"<<endl;
                return;
            }
            tail=tail->prev;
            if(tail){
                free(tail->next);
                tail->next=NULL;
            } else {
                free(head);
                head=NULL;
            }
            size--;
        }
        int remove(int num){
            node *cur=head;
            node *temp;
            int pos=1;
            if(size==0){
                return -1;
            }
            if(size==1){
                if(head->elem==num){
                    head=NULL;
                    tail=NULL;
                    size--;
                    return pos;
                } else {
                    return -1;
                }
            }
            while (cur){
                if(cur->elem==num){
                    if(cur==head){
                        head=cur->next; 
                        head->prev=NULL;
                        free(cur);
                        cur=NULL;
                    } else {
                        temp->next=cur->next;
                        free(cur);
                        cur=NULL;
                        if(pos==size){
                            tail=temp;
                            size--;
                            return pos;
                        }
                        cur=temp->next;
                        cur->prev=temp;
                    }
                size--;
                return pos;
                } else {
                    temp=cur;
                    cur=cur->next;
                }
             pos++;
            }
            return -1;
            /*node* curr = head;
            int ctr = 1;
            while (curr != nullptr) {
                if (curr->elem == num) {
                    if (ctr == 1) {
                        removeFirst();
                        return ctr;
                    } else {
                        if (ctr == size) {
                            removeLast();
                            return ctr;
                        }
                    }
                    node* pred = curr -> prev;
                    node* succ = curr -> next;
                    pred -> next = succ;
                    succ -> prev = pred;
                    free(curr);
                    size--;
                    return ctr;
                }
                curr = curr->next;
                ctr++;
            }

            return -1;*/
        }
        void combine(DoublyLinkedList* other){
            if(!other->head){
                return;
            }
            if(!head){
                this->head = other->head;
                this->tail = other->tail;
            } else {
                this->tail->next = other->head;
                other->head->prev = this->tail;
                this->tail = other->tail;
            }
            other->head = other->tail = NULL;
        }
        int retain(int num){
            int ctr=0;
            node* cur=head;
            node* temp, *holder;
            while(cur != tail){
                if(cur->elem >= num){
                    holder=cur;
                    cur=cur->next;
                } else {
                    temp=cur->next;
                    free(cur);
                    cur=NULL;
                    cur=temp;
                    head=cur;
                    ctr++;
                }
            }
            holder->next=tail;
            tail->prev=holder;
            size -= ctr;
            return ctr;
        }
        int corner(int left, int right){
            node* l = head;
            node* r = tail;
            //int holder = 0;
            /*if(left==1 && right==1){
                head->next=tail;
                tail->prev=head;
                size -= (left+right);
                return (left+right);
            } else {
                for(int i=0;i<left;i++){
                    l=l->next;
                }
                for(int j=0;j<right;j++){
                    r=r->prev;
                }
                l->next=r;
                r->prev=l;
            }*/
            for(int i=1;i<left;i++){
                l=l->next;
            }
            for(int j=1;j<right;j++){
                r=r->prev;
            }
            l->next=r;
            r->prev=l;
            int holder = size - (left+right);
            size -= holder;
            return holder;
        }
        
        void print(){
            node* cur1=head;
            node* cur2=tail;
            if(size==0){
                cout<<"No elements"<<endl;
                return;
            }
            cout<<"Size: "<<size<<endl;
            cout<<"For checking, Head = "<<head->elem<<", Tail = "<<tail->elem<<endl;
            cout<<"Printing from head: ";
            for(int i=0;i<size;i++){
                cout<<cur1->elem;
                if(i<size-1){
                    cout<<"->";
                }
                cur1=cur1->next;
            }
            cout<<endl<<"Printing from tail: ";
            for(int i=0;i<size;i++){
                cout<<cur2->elem;
                if(i<size-1){
                    cout<<"->";
                }
                cur2=cur2->prev;
            }
            cout<<endl;
        }
};