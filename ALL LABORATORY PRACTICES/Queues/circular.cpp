#include<iostream>
#include"C:\Users\Nicole Ejares\OneDrive\Documents\COLLEGE\Sophomor 1st Semester SY 2023-2024\CSIT221-Data Structures and Algorithms\ALL LABORATORY PRACTICE\Deques\dequelist.h"
using namespace std;

int main(){
    DequeList* deque = new DequeList();
    char op;
    int num;

    do {
        cout<<"Enter op: ";
        cin>>op;
        switch (op){
        case 'f':
            cin>>num;
            deque->addFirst(num);
            break;
        case 'l':
            cin>>num;
            deque->addLast(num);
            break;
        case 'F':
            cout<<"Removed "<<deque->removeFirst()<<endl;
            break;
        case 'L':
            /* code */
            break;
        case 'p':
            /* code */
            break;
        case 'x':
            /* code */
            break;
        default:
            cout<<"Invalid option"<<endl;
            break;
        }
    } while (op != 'x');
    return 0;
}