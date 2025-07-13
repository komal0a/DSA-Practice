class Solution {
public:
    long long floorSqrt(long long n)  {
      long long l=0; long long h=n;
 
      while(l<=h){
         long long mid=l+(h-l)/2;
         if(1LL*mid*mid<=n){
            l=mid+1;
         }else{
            h=mid-1;
         }
      } 
      return h;
    }
};