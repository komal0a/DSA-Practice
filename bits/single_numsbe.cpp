class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int num=1;num<nums.size();num++){
            ans^=nums[num];
        }
        return ans;
    }
};