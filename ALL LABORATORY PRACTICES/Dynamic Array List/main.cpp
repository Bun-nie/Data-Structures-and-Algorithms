#include <iostream>
#include "dynamicarraylist.h"
using namespace std;

int main() {
    List* list = new DArrayList();
    char ch;
    int num, pos;
    do {
        cout << "Op: ";
        cin >> ch;
        switch (ch) {
            case 'a':
                cin >> num;
                list->add(num);
                break;
            case 'g':
                cin >> pos;
                cout<< "Element in "<<pos<< " is "<<list->get(pos)<<endl;
                break;
            case '@':
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case '-':
                cin >> num;
                cout<<"Removed element at position "<<list->remove(num)<<endl;
                break;
            case 'r':
                cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
                break;
            case 'R':
                cin >> num;
                cout << "Removed " << list->removeAll(num) << " element/s" << endl;
                break;
            case 'f':
                list->flip();
                break;
            case '+':
                cin >> num;
                list->plus(num);
                break;
            case 's':
                cout << "Sum: " << list->summation() << endl;
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