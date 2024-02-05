#include<iostream>
#include"C:\Users\Nicole Ejares\OneDrive\Documents\COLLEGE\Sophomor 1st Semester SY 2023-2024\CSIT221-Data Structures and Algorithms\ALL LABORATORY PRACTICE\Dynamic Array List\dynamicarraylist.h"
#include"heap.h"
#include"cmath"
using namespace std;

class ArrayHeap : public Heap {
    int* array;
    int index;
    int size;

    //Helper functions
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void exchange(int i1, int i2){
        int temp = array[i1];
        array[i1] = array[i2];
        array[i2] = temp;
    }

    void dynamic_add(){
        int new_size = ceil(size * 1.5);
        int* new_array = (int*)realloc(array, new_size*sizeof(int));
        size = new_size;
        array = new_array;

    }
    void dynamic_reduce(){
        if(size == 4)
            return;
        int new_size = floor(size * 2.0/3);
        int* new_array = (int*)realloc(array, new_size*sizeof(int));
        size = new_size;
        array = new_array;
    }

    public:
        ArrayHeap(){
            index = 0;
            size = 4;
            array = (int*)calloc(size, sizeof(int));
        }
        //Other Methods
        void insert(int num){
            if(index == size){
                dynamic_add();
            }
            
            int cur = index;
            array[index++] = num;
            while (cur > 0){
                int parent_index = parent(cur);
                if(array[cur] > array[parent_index]){
                    swap(parent_index, cur);
                } cur = parent_index;
            }
        }
        int remove(int num){
            //temporary still needs to be implemented
            return 0;
        }
        int removeMax(){
            int temp = array[0];
            array[0] = array[index-1];
            int cur = 0;
            array[--index] = 0;

            if(index < floor(2.0/3 * size)){
                dynamic_reduce();
            }
            int left_index, right_index, more;
            while(left(cur) < index){
                left_index = left(cur);
                right_index = right(cur);
                more = left_index;

                if(right_index < index && array[right_index] > array[left_index]){
                    more = right_index;
                }
                if(array[more] > array[cur]){
                    swap(more, cur);
                    cur = more;
                } else {
                    break;
                }
            }
            return temp;
        }
        int search(int num){
            int cur = 0;
            while(cur < index){
                if(array[cur] == num){
                    break;
                }
                if(cur == index && array[cur] != num){
                    cur = -2;
                }
                cur++;
            }
            return cur + 1;
        }  

        int getSize(){
            return index;
        }
        bool isEmpty(){
            return index == 0;
        }

        void print(){
            for(int i=0;i<size;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
};