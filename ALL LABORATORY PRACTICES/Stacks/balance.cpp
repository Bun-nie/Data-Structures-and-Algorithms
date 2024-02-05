#include<iostream>
using namespace std;

typedef struct node {
    char data;
    node* next;
} node;

class LinkedList {
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

    void addHead(char str){
        node* n = new node;
        n->data = str;
        n->next = head;
        head = n;
        if(tail==NULL){
            tail = n;
        }
        size++;
    }

    char getHead(){
        return head->data;
    }
    
    char removeHead(){
        node* temp = head;
        char str = temp->data;
        head = head->next;
        free(temp);
        temp=NULL;
        size--;
        return str;
    }

    void print(){
        node* cur = head;
        cout<<"Size = "<<size<<endl;
        if(size==0)
            return;
        cout<<"For checking, Head: "<<head->data<<", Tail: "<<tail->data<<endl;
        while (cur != NULL) {
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

class ArrayStack {
    LinkedList* array;
    public:
        ArrayStack(){
            array = new LinkedList();
        }
        void push(char e){
            array->addHead(e);
        }
        char pop(){
            if(size()==0){
                return 'e';
            }
            char str = array->removeHead();
            return str;
        }
        char top(){
            if(size()==0){
                return 'e';
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

int isBalanced(string str){
        /*char temp;
        ArrayStack* stack = new ArrayStack();
        for(int i=0;i<str.length();i++){
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){
                stack->push(str[i]);
            }
            if(stack->isEmpty()){
                return 3;
                break;
            }
            if(str[i]==')' || str[i]=='}' || str[i]==']'){
                temp = stack->pop();
                if(temp=='(' && str[i] != ')' ||
                    temp=='{' && str[i] != '}' ||
                    temp=='[' && str[i] != ']'){
                        return 1;
                }
            }
        }
        if(stack->size() > 0){
            return 2;
        }
        return 0;
        */
       ArrayStack* stack = new ArrayStack();
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            
            if (ch == '(' || ch == '{' || ch == '[') {
                stack->push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (stack->isEmpty()) {
                    return 3;  // Lacks opening parentheses.
                }
    
                char top = stack->top();
                stack->pop();
    
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return 1;  // Mismatch.
                }
            }
        }
    
        if (!stack->isEmpty()) {
            return 2;  // Lacks closing parentheses.
        }
    
        return 0;  // Balanced.
    }

int main(){
    string exp;
    do{
        cout<<"Enter expression: ";
        cin>>exp;
        switch (isBalanced(exp))
        {
        case 1:
            cout<<"Mismatch"<<endl;
            break;
        case 2:
            cout<<"Lacking Closing"<<endl;
            break;
        case 3:
            cout<<"Lacking Opening"<<endl;
            break;
        case 0:
            cout<<"Balanced"<<endl;
            break;
        default:
            break;
        }
    } while(exp != "Done");
    
    return 0;
}