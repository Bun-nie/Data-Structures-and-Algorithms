#include<iostream>
#include"lupa.h"
#include"C:\Users\Nicole Ejares\OneDrive\Documents\COLLEGE\Sophomor 1st Semester SY 2023-2024\CSIT221-Data Structures and Algorithms\ALL LABORATORY PRACTICE\Queues\queuelist.h"
using namespace std;

class Puno : public Lupa {
    node* root;
    int size;

    node* create_node(node* p, int e){
        node* n = (node*)malloc(1*sizeof(node));
        n->elem = e;
        n->parent = p;
        n->left = NULL;
        n->right = NULL;
        size++;
        return n;
    }

    public:
    Puno(){
        root = NULL;
        size = 0;
    }

    node* left(node* n){
        return n->left;
    }
    node* right(node* n){
        return n->right;
    }
    node* sibling(node* n){
        node* eomma = n->parent;
        if(!eomma){
            return NULL;
        }
        if(eomma->left == n){
            return eomma->right;
        } else {
            return eomma->left;
        }
    }
    node* addRoot(int e){
        if(root){
            throw logic_error("Root already exists");
            return NULL;
        }
        root = create_node(NULL, e);
        return root;
    }
    node* addLeft(node* p, int e){
        if(p->left){
            throw logic_error(to_string(p->elem) + " already has a left child");
        }
        node* n = create_node(p, e);
        p->left = n;
        return n;
    }
    node* addRight(node* p, int e){
        if(p->right){
            throw logic_error(to_string(p->elem) + "already has right child");
        }
        node* n = create_node(p, e);
        p->right = n;
        return n;
    }
    int remove(node* n){
        int num = n->elem;
        //has 2 children
        if(n->left && n->right){
            throw logic_error("Cannot remove " + to_string(n->elem) + " for it has 2 children");
            return 0;
        }
        //has no children
        if(!n->left && !n->right){
            if(n->parent){
                node* gparent = n->parent;
                if(gparent->left == n){
                    gparent->left = NULL;
                } else {
                    gparent->right = NULL;
                }
            } else {
                root = NULL;
            }
        } else {
            node* child;
            if(n->left){
                child = n->left;
            } else {
                child = n->right;
            }
            if(n->parent){
                node* gparent = n->parent;
                if(gparent->left == n){
                    gparent->left = child;
                } else {
                    gparent->right = child;
                }
            } else {
                root = child;
                child->parent = NULL;
            }
        }
        size--;
        free(n);
        return num;
    }
    void preorder(){
        pre_traverse(root);
    }
    void pre_traverse(node* n){
        cout << n->elem << " ";
        if(n->left){
            pre_traverse(n->left);
        }
        if(n->right){
            pre_traverse(n->right);
        }
    }
    void inorder(){
        in_traverse(root);
    }
    void in_traverse(node* n){
        if(n->left){
            in_traverse(n->left);
        }
        cout << n->elem << " ";
        if(n->right){
            in_traverse(n->right);
        }
    }
    void postorder(){
        post_traverse(root);
    }
    void post_traverse(node* n){
        if(n->left){
            post_traverse(n->left);
        }
        if(n->right){
            post_traverse(n->right);
        }
        cout << n->elem << " ";
    }
    void breadthfirst(){
        breadth_traverse(root);
    }
    void breadth_traverse(node* n){
        if(!root){
            return;
        }
        QueueList* bbq;
        bbq->enqueue(n->elem);
        while(!bbq->isEmpty()){
            node* cur = bbq->dequeue();
            cout<< cur->elem << " ";
            if(cur->left){
                bbq->enqueue(cur->left->elem);
            }
            if(cur->right){
                bbq->enqueue(cur->right->elem);
            }
        }
    }
    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }
};