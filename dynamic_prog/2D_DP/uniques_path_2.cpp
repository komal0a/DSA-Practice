//leetcode uniques paths -2 63
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //SPACE OPTIMIZATION
        //0- you can move
        //1-you cannot move
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();

         vector<int>prev(n,0);

        for (int row = 0; row < m; row++) {
            vector<int>cur(n,0);
            for (int col = 0; col < n; col++) {
             if (obstacleGrid[row][col] == 1) {
                    cur[col] = 0;  // Obstacle cell
                } else if (row == 0 && col == 0) {
                    cur[col] = 1;  // Starting point
                } else {
                    int up = (row > 0) ? prev[col] : 0;
                    int left = (col > 0) ? cur[col - 1] : 0;
                    cur[col] = up + left;
                }
    }
    prev=cur;
    }
    return prev[n-1];
    }

    
};

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         //TABULATION
//         //0- you can move
//         //1-you cannot move
//         int m= obstacleGrid.size();
//         int n= obstacleGrid[0].size();

//          vector<vector<int>>dp(m, vector<int>(n,-1));

//         for (int row = 0; row < m; row++) {
//             for (int col = 0; col < n; col++) {
//              if (obstacleGrid[row][col] == 1) {
//                     dp[row][col] = 0;  // Obstacle cell
//                 } else if (row == 0 && col == 0) {
//                     dp[row][col] = 1;  // Starting point
//                 } else {
//                     int up = (row > 0) ? dp[row - 1][col] : 0;
//                     int left = (col > 0) ? dp[row][col - 1] : 0;
//                     dp[row][col] = up + left;
//                 }
//     }
//     }
//     return dp[m-1][n-1];
//     }

    
// };

// class Solution {
// public:
// int solve(vector<vector<int>>& grid, int row, int col,vector<vector<int>>& dp){
//         //MEMOIZATION
//         if (row < 0 || col < 0) return 0;
//         if (grid[row][col] == 1) return 0;
//         if (row == 0 && col == 0) return 1;
//         if (dp[row][col] != -1) return dp[row][col];

//         int up = solve(grid, row - 1, col, dp);
//         int left = solve(grid, row, col - 1, dp);

//         return dp[row][col] = up + left;
        
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         //0- you can move
//         //1-you cannot move
//         int m= obstacleGrid.size();
//         int n= obstacleGrid[0].size();

//         vector<vector<int>>dp(m, vector<int>(n,-1));

//         return solve(obstacleGrid, m-1,n-1,dp);
//     }
// };