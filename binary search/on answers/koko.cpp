class Solution {
public:
    static long long func(vector<int>& piles,int mid,int h){
        long long temp=0;
        for(int i=0; i<piles.size();i++){
             temp += (piles[i] + mid - 1) / mid;
        }
       return temp;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1; long long high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            long long mid=low+(high-low)/2;
            long long midn=(func(piles,mid,h));
            if(midn>h){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return (int)low;
    }
};