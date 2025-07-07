class Solution {
public:
    int solve(vector<int>&nums, int k){
        int l=0; int r=0; int cnt=0;
        int odd=0; int n= nums.size();

        while(r<n){
             if(nums[r] % 2 != 0){
                    odd++;
                }
            while(odd>k && l<=r){
                if(nums[l] % 2 != 0){
                    odd--;
                }
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=solve(nums,k)-solve(nums,k-1);
        return ans;
    }
};