#include<iostream>
#include"circularlinkedlist.h"
using namespace std;

int main () {
    List* list = new CLL();
    int num;
    char op;
    do {
        cout << "Op: ";
        cin >> op;

        switch (op) {
            case 'f':
                cin >> num;
                list->addFirst(num);
                break;
            case 'l':
                cin>>num;
                list->addLast(num);
                break;
            case 'p':
                list->display();
                break;
            case 'r':
                list->rotate();
                break;
            case 'R':
                cout<<"Removed: "<<list->removeFirst()<<endl;
                break;
            case 'x':
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid operation"<<endl;
                break;
        }
    } while (op != 'x');
}