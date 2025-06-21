class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n= val.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        
        for(int i=0; i<=W;i++){
            if(wt[0]<=i)dp[0][i]=val[0];
            else dp[0][i]=0;
        }
        
        for(int row=1;row<n;row++){
            for(int col=0;col<=W;col++){
                int take=0; 
                if(wt[row]<=col){
                    take=val[row]+dp[row-1][col-wt[row]];
                }
                int non_take=dp[row-1][col];
                dp[row][col]=max(take,non_take);
            }
        }
        return dp[n-1][W];
    }
};

// class Solution {
//   public:
//     int solve(vector<int>& val,vector<int>& wt,int W,vector<vector<int>>& dp,int idx){
//         //MEMOIZATION
//         if(idx==0){
//         if(wt[0]<=W){
//             return val[0];
//         }    else{
//             return 0;
//         }
//         }
//         if(dp[idx][W]!=-1)return dp[idx][W];
        
//         int take=0;
//         if(wt[idx]<=W){
//             take=val[idx]+solve(val,wt,W-wt[idx],dp,idx-1);
//         }
//         int non_take=solve(val,wt,W,dp,idx-1);
        
//         return dp[idx][W]=max(take,non_take);
//     }
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         // code here
//         int n= val.size();
//         vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        
//         return solve(val,wt,W,dp,n-1);
//     }
// };