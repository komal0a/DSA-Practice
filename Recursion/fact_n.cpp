#include<iostream>
using namespace std;

int print(int n,int i){
    if (n==0)return i;
     i*=n;
    return print(n-1,i);
    
}

int main(){
    int n;
    cin>>n;  
    cout<< print(n,1);
    return 0;
}