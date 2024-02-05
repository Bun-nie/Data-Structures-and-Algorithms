#include"node.h"
class Lupa {
    public:
    //getters
    virtual node* left(node* p) = 0;
    virtual node* right(node* p) = 0;
    virtual node* sibling(node* p) = 0;

    //setters
    virtual node* addRoot(int e) = 0;
    virtual node* addLeft(node* p, int e) = 0;
    virtual node* addRight(node* p, int e) = 0;

    //update
    //virtual int set(node* p, int e) = 0;
    //virtual void attach() = 0;
    virtual int remove(node* n) = 0;

    //traversals
    virtual void preorder() = 0;
    virtual void inorder() = 0;
    virtual void postorder() = 0;
    virtual void breadthfirst() = 0;

    //others
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    //virtual void print() = 0;
};