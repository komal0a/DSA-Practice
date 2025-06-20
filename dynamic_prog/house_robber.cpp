//leetcode-198 house robber
class Solution {
public: 
    int solve(vector<int>& nums,int ind){
        //space optimization
        int n= nums.size();
      int prev=nums[0];
      int prev2=0;
       for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
        take+=prev2;
        }
        int non_take=0+prev;

        int curi=max(take,non_take);
        prev2=prev;
        prev=curi;
     }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0)return 0;
        if (n==1)return nums[0];
        return solve(nums,n-1);
    }
};
// class Solution {
// public: 
//     int solve(vector<int>& nums,int ind, vector<int>&dp){
//         //TABULATION
//         int n= nums.size();
//        dp[0]=nums[0];
//        for(int i=1;i<n;i++){
//         int take=nums[i];
//         if(i>1){
//         take+=dp[i-2];
//         }
//         int non_take=0+dp[i-1];

//         dp[i]=max(take,non_take);
//      }
//         return dp[n-1];
//     }
//     int rob(vector<int>& nums) {
//         int n= nums.size();
//         if(n==0)return 0;
//         if (n==1)return nums[0];
//         vector<int>dp(n,-1);
//         return solve(nums,n-1,dp);
//     }
// };
    // int solve(vector<int>& nums,int n, vector<int>&dp){
    //     //memoization
    //     if(n==0)return nums[0];
    //     if(n<0)return 0;
    //     if(dp[n]!=-1)return dp[n];

    //     int take=nums[n]+solve(nums,n-2,dp);
    //     int non_take=0+solve(nums,n-1,dp);

    //     return dp[n]=max(take,non_take);
    // }
    // int rob(vector<int>& nums) {
    //     int n= nums.size();
    //     vector<int>dp(n,-1);
    //     return solve(nums,n-1,dp);
    // }