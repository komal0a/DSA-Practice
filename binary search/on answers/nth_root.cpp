class Solution {
public:
  int func(int val,int n, int m){
    long long temp=1;
    for(int i=0; i<n;i++){
       temp*=val;
      
    }if(temp==m)return 0;
    if(temp>m)return 2;
    return 1;
  }
  int NthRoot(int N, int M) {
       int low=0; int high=M;
       while(low<=high){
        int mid=low+(high-low)/2;
        int midN=func(mid,N,M);
        if(midN==2){
          high=mid-1;
        }else if(midN==0){
          return mid;
        }else{
          low=mid+1;
        }
       }
       return -1;
    }
};
