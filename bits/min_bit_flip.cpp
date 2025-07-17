class Solution {
public:
    int minBitFlips(int start, int goal) {
        int word=start ^ goal;
            int cnt=0;
       while(word){
            cnt+=word&1;
            word>>=1;
       }
        return cnt;
        
    }
};