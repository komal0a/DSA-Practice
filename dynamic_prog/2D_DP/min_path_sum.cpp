//leetcode 64 minimum path sum
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        //SPACE OPTIMIZATION
        int n= grid.size();
        int m =grid[0].size();

        vector<int>prev(m,0);

        for(int row=0; row<n;row++){
             vector<int>cur(m,0);
            for(int col=0;col<m;col++){
                if(row==0 && col==0){
                    cur[col]=grid[row][col];
                    continue;
                }
                else {
                 int up = (row > 0) ? prev[col] : 1e9;
                 int left = (col > 0) ? cur[col - 1] : 1e9;

                   cur[col]=grid[row][col] + min(up,left);
                }
            }
            prev=cur;
        }
        return prev[m-1];
    }
};


// int minPathSum(vector<vector<int>>& grid) {
//         //TABULATION
//         int n= grid.size();
//         int m =grid[0].size();

//         vector<vector<int>>dp(n,vector<int>(m,-1));

//         for(int row=0; row<n;row++){
//             for(int col=0;col<m;col++){
//                 if(row==0 && col==0){
//                     dp[0][0]=grid[0][0];
//                     continue;
//                 }
//                 else {
//                  int up = (row > 0) ? dp[row - 1][col] : 1e9;
//                  int left = (col > 0) ? dp[row][col - 1] : 1e9;

//                    dp[row][col]=grid[row][col] + min(up,left);
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

// class Solution {
// public:
//     int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){
//         //MEMOIZATION
//        if(row==0 && col==0)return grid[0][0];
//        if(row<0 ||col<0)return 1e9;
//        if(dp[row][col]!=-1)return dp[row][col];

//        int up=grid[row][col]+solve(grid,dp,row-1,col);
//        int left=grid[row][col]+ solve(grid,dp,row,col-1);

//        return dp[row][col]=min(up,left);

//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m =grid[0].size();

//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(grid,dp,n-1,m-1);
//     }
// };