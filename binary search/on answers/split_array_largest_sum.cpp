class Solution {
public:
    int func(vector<int>& nums, int k,int max_val){
        int sum=0;
        int cnt=1;
        for(int i=0; i<nums.size();i++){
            if(sum+nums[i]>max_val){
                cnt++;
                sum=0;
            }
            sum+=nums[i];
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
         int h= accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(nums,k,mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};