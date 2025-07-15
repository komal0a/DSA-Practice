class Solution {
public:
    int countSetBits(int n) {
        // Your code goes here
        int cnt=0;
        while(n>1){
            if(n&1 ==1) cnt++;
            n=n/2;
        }
        if(n==1)cnt+=1;
        return cnt;
    }
};