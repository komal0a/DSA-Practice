class Solution {
public:
    int func(int divisor,vector<int>& nums, int threshold){
        int temp=0;
        for(int i=0; i<nums.size();i++){
            temp+=(nums[i] + divisor - 1) / divisor;
        }
        if(temp<=threshold)return 1;
        return 0;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(mid,nums,threshold)){
                //if 1 then it leads threshold
                h=mid-1;

            }else{
                l=mid+1;
            }
        }
        return l;
    }
};