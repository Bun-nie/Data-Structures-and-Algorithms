#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    List* list = new LinkedList();
    char ch;
    int num, pos;
    do {
        cout << "Op: ";
        cin >> ch;
        switch (ch) {
            case 'h':
                cin >> num;
                list->addHead(num);
                break;
            case 't':
                cin >> num;
                list->addTail(num);
                break;
            case 'g':
                cin >> pos;
                cout<<"Element at "<<pos<<" is "<<list->get(pos)<<endl;
                break;
            case 'r':
                cin>>num;
                if(list->remove(num)==-1){
                    cout<<num<<" does not exist in the list"<<endl;
                } else {
                    cout<<"Removed "<<num<<" at position "<<list->remove(num)<<endl;
                }
                break;
            case 'd':
                cin>>pos;
                if(list->removeAt(pos)==-1){
                    cout<<"No element in position "<<pos<<endl;
                } else {
                    cout<<"Remove element "<<list->removeAt(pos)<<endl;
                }
                break;
            case '@':
                cin>>num>>pos;
                list->addAt(num, pos);
                break;
            case 'R':
                cin >> num;
                cout<<"Removed "<<list->removeAll(num)<<" element/s"<<endl;
                break;
            case 'f':
                list->flip();
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 'x');
    return 0;
}