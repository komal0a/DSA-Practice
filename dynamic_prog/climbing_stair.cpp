//leetcode climbing stairs
class Solution {
public:
//     int solve(int n,vector<int>&dp){
    //memoization
//         if(n==0)return 1;
//         if(dp[n]!=-1)return dp[n];

//         int one_step=solve(n-1,dp);
//         int two_step=0;
//         if(n>1){
//         two_step=solve(n-2,dp);
//         }
        
//          return dp[n]= one_step + two_step;
//      }    
// int climbStairs(int n) {
//         vector<int>dp(n+1,-1);
//         return solve(n,dp);
//     }

    int solve(int n, vector<int>&dp){
        dp[0]=1;

        for(int i=1;i<=n;i++){
            int one_step=dp[i-1];
            int two_step=0;
            if(i>1){
                two_step=dp[i-2];
            }
            dp[i]=one_step+two_step;
        }
        return dp[n];
    }
    int climbStairs(int n) {
        //tabulation
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
        
};