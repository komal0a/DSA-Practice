class Solution {
public:
    int func(vector<int> &nums, int dist,int k){
        int last=0;
        int cnt=1;
        for(int i=1; i<nums.size();i++){
            if(nums[i]-nums[last]>=dist){
                cnt++;
                last=i;
            }
        }
        if(k<=cnt)return 1;
        return 0;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=1; int h=nums[nums.size()-1]-nums[0];
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(nums,mid,k)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};