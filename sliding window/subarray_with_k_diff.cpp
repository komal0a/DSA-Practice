class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n= nums.size();
        unordered_map<int,int>mp;
        int l=0; int r=0; int cnt=0;

        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int mm=solve(nums,k)-solve(nums,k-1);
        return mm;
    }
};