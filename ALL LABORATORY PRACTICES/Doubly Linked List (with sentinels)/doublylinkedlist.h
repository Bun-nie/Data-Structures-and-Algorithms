#include<iostream>
#include"list.h"
#include"node.h"
using namespace std;

class DLL : public List {
    node *head, *tail;
    int size;

    void addBetween(int num, node* before, node* after){
        node *n = (node*)malloc(sizeof(node));
        n->elem=num;
        n->next=after;
        n->prev=before;
        before->next=n;
        after->prev=n;
        size++;
    }

    void removeNode(node *n){
        node *before = n->prev;
        node *after = n->next;
        before->next=after;
        after->prev=before;
        free(n);
        n=NULL;
        size--;
    }

public:
    DLL(){
        head = (node*) calloc (1, sizeof(node));
        tail = (node*) calloc (1, sizeof(node));
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addHead(int num){
        addBetween(num, head, head->next);
    }
    void addTail(int num){
        addBetween(num, tail->prev, tail);
    }
    void addAt(int num, int pos){
        node* cur = head->next;
        int index=1;
        while(index<pos && cur!=tail){
            cur=cur->next;
            index++;
        }
        addBetween(num, cur->prev, cur);
    }

    void removeFirst(){
        if(size==0){
            return;
        }
        node* temp = head->next;
        head->next = temp->next;
        free(temp);
        temp=NULL;
        size--;
        return;
    }
    void removeLast(){
        if(size==0){
            return;
        }
        if(size==0){
            return;
        }
        node* temp = tail->prev;
        tail->prev = temp->prev;
        free(temp);
        temp=NULL;
        size--;
        return;
    }

    int remove(int num){
        node* cur=head->next;
        int index=1;

        while(cur != tail){
            if(cur->elem == num){
                removeNode(cur);
                return index;
            }
            cur=cur->next;
            index++;
        }
        return -1;
    }
    int removeAt(int pos){
        node *cur = head->next;
        int index=1;
        while (cur != tail && index<pos){
            cur=cur->next;
            index++;
        }
        int num = cur->elem;
        removeNode(cur);
        return num;
    }
    int removeAll(int num){
        node *cur = head->next;
        node* temp;
        int ctr = 0;
        while (cur != tail){
            if(cur->elem==num){
                temp=cur;
                cur=cur->next;
                removeNode(temp);
                ctr++;
            } else {
                cur=cur->next;
            }
        }
        return ctr;
    }
    int get(int pos){
        node *cur = head->next;
        int index=1;
        while (cur != tail && index<pos){
            cur=cur->next;
            index++;
        }
        return cur->elem;
    }
    // int retain(int num){
    //     node* before = head;
    //     node* cur = head->next;
    //     node* temp;
    //     int ctr=0;
    //     while (cur != tail){
    //         if(cur->elem >= num){
    //             before->next=cur;
    //             cur->prev=before;
    //             before=cur;
    //             cur=cur->next;
    //         } else {
    //             temp=cur->next;
    //             free(cur);
    //             cur=NULL;
    //             cur=temp;
    //             ctr++;
    //         }
    //     }
    //     size -= ctr;
    //     tail->prev=before;
    //     before->next=tail;
    //     return ctr;
    // }
    // int corner(int num)
    // void reverse()
    // void swap()
    int insert(int num){
        node* n = new node;
        node* before, *after;
        n->elem = num;
        int flag = 1;
        if(size==0){
            n->next = tail;
            n->prev = head;
            head->next = n;
            tail->prev = n;
            size++;
            return 1;
        }
        node* cur = head->next;
        int ctr1 = 0;
        while(cur != tail && cur->elem < num){
            cur=cur->next;
            ctr1++;
        }
        cur=tail->prev;
        int ctr2 = 0;
        while(cur != head && cur->elem > num){
            cur=cur->prev;
            ctr2++;
        }

        if(ctr1<=ctr2 || size==1){
            //for testing
            cout<<ctr1<<" "<<ctr2<<endl;
            cur=head->next;
            while(cur != tail && cur->elem < num){
                cur=cur->next;
            }
            before = cur->prev;
            after = cur;
            n->prev = before;
            n->next = after;
            before->next = n;
            after->prev = n;
            flag = 1;
        } else {
            //for testing
            cout<<ctr1<<" "<<ctr2<<endl;
            cur=tail->prev;
            while(cur != head && cur->elem > num){
                cur=cur->prev;
            }
            before = cur;
            after = cur->next;
            n->prev = before;
            n->next = after;
            before->next = n;
            after->prev = n;
            flag = 2;
        }
        size++;
        return flag;
    }
    void print(){
        if(size==0){
            cout<<"Empty"<<endl;
            return;
        }
        node* cur = head->next;
        cout<<"Size = "<<size<<endl;
        cout<<"Printing from head:"<<endl;
        for(int i=0;i<size;i++){
            cout<<cur->elem;
            if(i<size-1){
                cout<<"->";
            }
            cur=cur->next;
        }
        cur = tail->prev;
        cout<<endl<<"Printing from tail:"<<endl;
        for(int i=0;i<size;i++){
            cout<<cur->elem;
            if(i<size-1){
                cout<<"<-";
            }
            cur=cur->prev;
        }
        cout<<endl;
    }
};