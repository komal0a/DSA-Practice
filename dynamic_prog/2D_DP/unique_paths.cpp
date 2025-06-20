//leetcode 62
class Solution {
public:
    int uniquePaths(int m, int n) {
        //Space optimization
        vector<vector<int>>dp(m,vector(n,-1));
        vector<int>prev(n,0);
        prev[0]=1;

        for(int row=0;row<m;row++){
                vector<int>cur(n,0);
            for(int col=0; col<n;col++){
                    if(row==0 && col==0){
                       cur[col]=1;
                    }
                    else{
                        int up=0;int left=0;
                    if(row>0) up=prev[col];
                    if(col>0) left=cur[col-1];
                    cur[col]=up+left;
                }
            }
                prev=cur;//after every row
        }
        return prev[n-1];
    }
};

// class Solution {
// // public:
//     int uniquePaths(int m, int n) {
//         //TABULATION
//         vector<vector<int>>dp(m,vector(n,-1));
//         for(int row=0;row<m;row++){
//             for(int col=0; col<n;col++){
//                     if(row==0 && col==0){
//                         dp[row][col]=1;
//                     }
//                     else{
//                         int up=0;int left=0;
//                     if(row>0) up=dp[row-1][col];
//                     if(col>0) left=dp[row][col-1];
//                     dp[row][col]=up+left;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
//     // int solve(int m , int n, int row, int col,vector<vector<int>>& dp){
    //     //MEMOIZATION
    //     if(row==0 && col==0){
    //         return 1;
    //     }

    //     if(row<0 || col<0 )return 0;

    //     if(dp[row][col]!=-1)return dp[row][col];

    //     int up=solve(m,n,row-1,col,dp);
    //     int left=solve(m,n,row,col-1,dp);

    //     return dp[row][col]=up+left;
        
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>dp(m,vector(n,-1));
    //     return solve(m,n,m-1,n-1,dp);
    // }