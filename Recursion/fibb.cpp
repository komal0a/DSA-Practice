#include<iostream>
using namespace std;

int fibb(int n){
if(n<=1)return n;

return fibb(n-1)+fibb(n-2);
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n;i++){
        cout<<fibb(i)<<" ";
    }
    cout<<endl;
    return 0;
}