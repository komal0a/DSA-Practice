// Check if there exists a subsequence with sum K
class Solution{
    public:
    void solve(bool& ans,vector<int>&nums,int n, int target,int i){
            if(i>=n){
                if(target==0)ans=true;
                return;
            }

            solve(ans,nums,n,target-nums[i],i+1);

            solve(ans,nums,n,target,i+1);
        }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
        bool ans=false;
        int n= nums.size();

        solve(ans,nums,n,k,0);
        return ans;
    }
};