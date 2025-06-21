class Solution{
  public:
    int solve(int index, int length, int price[], vector<vector<int>>& dp) {
        if (index == 0) {
            return length * price[0]; // base case: only 1st piece (length 1) allowed
        }

        if (dp[index][length] != -1) return dp[index][length];

        int notTake = solve(index - 1, length, price, dp);
        int take = INT_MIN;
        int rodLength = index + 1;

        if (rodLength <= length) {
            take = price[index] + solve(index, length - rodLength, price, dp);
        }

        return dp[index][length] = max(take, notTake);
    }
    int rodCutting(vector<int> price, int n) {
     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n - 1, n, price, dp);
    }
};
