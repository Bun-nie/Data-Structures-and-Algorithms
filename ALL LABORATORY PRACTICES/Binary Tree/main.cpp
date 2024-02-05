#include<iostream>
#include"puno.h"
using namespace std;
int main(){
    Puno* puno = new Puno();
    char op;
    int num;
    do {
        cout<<"Enter option: ";
        cin>>op;
        switch(op){
            case '_': //addRoot
                cin>>num;
                cout<<puno->addRoot(num)<<" has been added as root"<<endl;
                break;
            case '<': //addLeft
                cin>>num;
                break;
            case '>': //addRight
                cin>>num;
                break;
            case 'L': //Left
                break;
            case 'R': //Right
                break;
            case 'S': //Sibling
                break;
            case '#': //set
                cin>>num;
                break;
            case '+': //attach
                break;
            case '-': //remove
                break;
            case '/': //preorder traversal
                break;
            case '|': //inorder traversal
                break;
            case '\\': //postorder traversal
                break;
        }
    } while (op != 'x');
    return 0;
}