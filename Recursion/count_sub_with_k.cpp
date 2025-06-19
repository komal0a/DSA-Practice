// Count all subsequences with sum K
class Solution{
    public:    	
    void solve(int& ans,vector<int>&nums,int n, int target,int i){
            if(i>=n){
                if(target==0)ans++;
                return;
            }

            solve(ans,nums,n,target-nums[i],i+1);

            solve(ans,nums,n,target,i+1);
        }
    
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here]
        int ans=0;
        int n= nums.size();

        solve(ans,nums,n,k,0);
        return ans;
    }
};