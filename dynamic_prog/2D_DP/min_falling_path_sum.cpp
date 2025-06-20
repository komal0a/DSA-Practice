//leetcode 931
class Solution {
public:
    int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp,int n, int row,int col){
        //MEMOIZATION
        if (col < 0 || col >= n) return 1e9;

        if(row==n-1){
            return matrix[row][col];
        }

        if(dp[row][col]!=-1)return dp[row][col];

        int down=  matrix[row][col]+solve(matrix,dp,n,row+1,col);
         int l_diagonal=  matrix[row][col]+solve(matrix,dp,n,row+1,col-1); 
         int r_diagonal=  matrix[row][col]+solve(matrix,dp,n,row+1,col+1);

         return min(down,min(l_diagonal,r_diagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
    
        int mini=INT_MAX;
        // Start from all columns of the top row
        for (int col = 0; col < n; col++) {
            vector<vector<int>> dp(n, vector<int>(n, -1));
            mini = min(mini, solve(matrix, dp, n, 0,col));
        }


        return mini;
    }
};