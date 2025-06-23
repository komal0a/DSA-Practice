class Solution {
public:
    // int solve(vector<int>&nums,  vector<vector<int>>&dp,int i,int prev_i){
    //     if(i==nums.size())return 0;
        //memo
    //     if(dp[i][prev_i+1]!=-1)return dp[i][prev_i+1];

    //     int take=0;
    //     if( prev_i==-1 || nums[i]>nums[prev_i] ){
    //         take=1+solve(nums,dp,i+1,i) ;
    //     }
    //         int  non_take=0+solve(nums,dp,i+1,prev_i);
        
    //     return dp[i][prev_i+1]=max(take,non_take);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        // return solve(nums,dp,0,-1);
       vector<int>next(n+1,0),cur(n+1,0);
        //space optimization
        for(int i=n-1;i>=0;i--){
            for(int prev_i=i-1;prev_i>=-1;prev_i--){//i-1 coz prev_i is always previous to i
                 int take=0;
        if( prev_i==-1 || nums[i]>nums[prev_i] ){
            take=1+next[i+1] ;
         }
            int  non_take=next[prev_i+1];

            cur[prev_i+1]=max(take,non_take);
            }
            next=cur;
        }
        return next[0];
    }
};

//  vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//TABULATION
//         for(int i=n-1;i>=0;i--){
//             for(int prev_i=i-1;prev_i>=-1;prev_i--){//i-1 coz prev_i is always previous to i
//                  int take=0;
//         if( prev_i==-1 || nums[i]>nums[prev_i] ){
//             take=1+dp[i+1][i+1] ;
//          }
//             int  non_take=dp[i+1][prev_i+1];

//             dp[i][prev_i+1]=max(take,non_take);
//             }
//         }
//         return dp[0][0];