//Subfactorial problem
#include<iostream>
#include<cmath>;
using namespace std;
int subfactorial(int n){
    if(n <= 1){
        return 0;
    } else if(n == 2){
        return 1;
    } else {
        return n * subfactorial (n-1) + pow(-1, n);
    }
}
int main(){
    int n, res;
    do {
        cout<<"Enter a number: ";
        cin>>n;
        res = subfactorial(n);
        cout<<"!"<<n<<" = "<<res<<endl;
    } while (n >= 0);
    return 0;
}