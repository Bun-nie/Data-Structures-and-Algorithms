#include "list.h"
#include <cstdlib>
#include <iostream>
#define SIZE 10
using namespace std;

class ArrayList : public List {
    int *arr;
    int index;

  public:
    ArrayList() {
      arr = (int*) malloc(sizeof(int) * SIZE);
      index = 0;
    }
    int add(int num) {
      if(index>SIZE){
        return 0;
      }
      if(index==0){
          arr[index]=num;
          index++;
          return 1;
      }
      for(int i=index;i>0;i--){
          arr[i]=arr[i-1];
      }
      arr[0]=num;
      index++;
      return 1;
    }

    int addAt(int num, int pos) {
      if(index>SIZE){
        return 0;
      }
      if(pos>=index){
        arr[index] = num;
        index++;
        return 1;
      }
      for(int i=index;i>pos-1;i--){
        arr[i]=arr[i-1];
      }
      arr[pos-1]=num;
      index++;
      return 1;
    }

    int remove(int num) {
      for(int i=0;i<index;i++){
          if(arr[i]==num){
              for(int j=i+1;j<index;j++){
                  arr[j-1]=arr[j];
              }
              index--;
              return (i+1);
          }
      }
      return -1;
    }
    
    int size(){
    	return index;
	}

    void print() {
          if(index==0){
            cout<<"Empty"<<endl;
            return;
          }
          cout<<"Updated Array:"<<endl;
          for(int i=0;i<index;i++){
              cout<<arr[i];
              if(i<index-1){
                  cout<<", ";
              }
          }
          cout<<endl;
    }
};
