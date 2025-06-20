//leetcode 120 triangle
int minimumPathSum(vector<vector<int>> &triangle, int n) {
    // Create two arrays to store the current and previous row values
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row
    
    // Initialize the front array with values from the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            
            // Store the minimum of the two possible paths in the current row
            cur[j] = min(down, diagonal);
        }
        // Update the front array with the values from the current row
        front = cur;
    }
    
    // The front array now contains the minimum path sum from the top to the bottom of the triangle
    return front[0];
}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //TABULATION
        int n= triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int col=0; col<n;col++){
            dp[n-1][col]=triangle[n-1][col];
        }
       
        for(int i=n-2; i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }

};

// class Solution {
// public:
//     int solve(vector<vector<int>>& triangle,  vector<vector<int>>&dp,int n,int row,int col){
//         //we are starting from 0,0 coz we have variable ending
//         //MEMOIZATION
//         if(row==n-1){
//             return triangle[row][col];
//         }

//         if(dp[row][col]!=-1)return dp[row][col];

//         // we ll not get out of bouunds coz every element has diagonal element
//         int down=triangle[row][col]+solve(triangle,dp,n,row+1,col);
//         int r_down=triangle[row][col]+solve(triangle,dp,n,row+1,col+1);

//         return dp[row][col]=min(down,r_down);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n= triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return solve(triangle,dp,n,0,0);
//     }
// };