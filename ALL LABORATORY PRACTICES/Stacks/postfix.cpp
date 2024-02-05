#include<iostream>
using namespace std;

typedef struct node {
    int data;
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

    void addHead(int num){
        node* n = new node;
        n->data = num;
        n->next = head;
        head = n;
        if(tail==NULL){
            tail = n;
        }
        size++;
    }

    int getHead(){
        return head->data;
    }
    
    int removeHead(){
        node* temp = head;
        int num = temp->data;
        head = head->next;
        free(temp);
        temp=NULL;
        size--;
        return num;
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
        void push(int e){
            array->addHead(e);
        }
        int pop(){
            if(size()==0){
                return 'e';
            }
            int num = array->removeHead();
            return num;
        }
        int top(){
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

int calculate(string str){
    ArrayStack* stack = new ArrayStack();
    int num1, num2, res;
    string num;
    int converted;
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i]) || str[i]==' '){
            if(isdigit(str[i])){
                num += str[i];
            } else if (str[i]==' '){
                if(!num.empty()){
                    converted = stoi(num);
                    stack->push(converted);
                    num.clear();
                }
            }
        } else if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            num2 = stack->pop();
            num1 = stack->pop();
            switch(str[i]){
                case '+':
                    res = num1 + num2;
                    break;
                case '-':
                    res = num1 - num2;
                    break;
                case '*':
                    res = num1 * num2;
                    break;
                case '/':
                    res = num1 / num2;
                    break;
            }
            stack->push(res);
        } 
    }
    int fin_res = stack->pop();
    return fin_res;
}

int main(){
    string str;
    do {
        cout<<"Enter expression: ";
        getline(cin, str);
        cout<<"Result: "<<calculate(str)<<endl;
    } while (str != "Done");
    return 0;
}