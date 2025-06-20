//leetcode  frog jump
class Solution {
public:int n;
    int solve(vector<int>& heights,vector<int>&dp){
        //tabulation
        dp[0]=0;

        for(int i=1;i<n;i++){

        int one_step=abs(heights[i-1]-heights[i])+dp[i-1];
        int two_step=INT_MAX;
        if(i>1){
            two_step=abs(heights[i-2]-heights[i])+dp[i-2];
        }
        dp[i]=min(one_step,two_step);
        }

        return dp[n-1];
    }
    int frogJump(vector<int>& heights) {
         n=heights.size();
        vector<int>dp(n,-1);
        return solve(heights,dp);
    }
};
// class Solution {
// public:
//     int solve(vector<int>& heights, vector<int>& dp, int index) {
//memoizatoion
//         if (index == 0) return 0;
//         if (dp[index] != -1) return dp[index];

//         int one_step = abs(heights[index] - heights[index - 1]) + solve(heights, dp, index - 1);

//         int two_step = INT_MAX;
//         if (index > 1) {
//             two_step = abs(heights[index] - heights[index - 2]) + solve(heights, dp, index - 2);
//         }

//         return dp[index] = min(one_step, two_step);
//     }

//     int frogJump(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> dp(n, -1);
//         return solve(heights, dp, n - 1);
//     }
// };
