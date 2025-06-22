class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // TABULATION
        // // dp[n]=0;//starting from n this time
        // dp[n][0]=0;dp[n][1]=0;
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0; buy<=1;buy++){
                 if (buy == 0) { // We can buy the stock
                profit = max(0 + dp [i+ 1][0], -prices[i] + dp[i + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[i + 1][1], prices[i] + dp[i + 1][0]-fee);
            }

            dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }
};