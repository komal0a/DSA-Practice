#include <iostream>
using namespace std;

void printNumbers(int n, int i){
    if(n<i)return;

    cout<<n<<endl;
    printNumbers(n-1,i);
}
int main(){
    int n;
    cin>>n;
    printNumbers(n,1);
    return 0;
}