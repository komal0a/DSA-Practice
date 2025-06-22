class Solution {
public:
    //   long long solve(vector<int>& arr,  vector<vector<int>>& dp,int buy,int ind,int n){
        //MEMOIZATION
    //     if(ind==arr.size())return 0;

    //     if(dp[ind][buy]!=-1)return dp[ind][buy];
    //     long long profit=0;
    //     if(buy){
    //         profit=max(-arr[ind]+solve(arr,dp,0,ind+1,n),0+solve(arr,dp,1,ind+1,n));//buy,not buy
    //     }else{
    //         profit=max(arr[ind]+solve(arr,dp,1,ind+1,n),solve(arr,dp,0,ind+1,n));//sell,not sell
    //     }

    //     return dp[ind][buy]=profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return (int)solve(prices,dp,1,0,n);
        vector<long>prev(2,0);
        vector<long>cur(2,0);
        prev[0]=0;
        prev[1]=0;
        long profit=0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    profit= max(0+prev[0],-prices[i]+prev[1]);
                }
                if(buy==1 ){
                    profit=max(0+prev[1],prices[i]+prev[0]);
                }
                cur[buy]=profit;
            }
            prev=cur;
        }
        return cur[0];
    }
};
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        //TABULATION
        // // dp[n]=0;//starting from n this time
        // dp[n][0]=0;dp[n][1]=0;
        // int profit=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int buy=0; buy<=1;buy++){
        //          if (buy == 0) { // We can buy the stock
        //         profit = max(0 + dp [i+ 1][0], -prices[i] + dp[i + 1][1]);
        //     }

        //     if (buy == 1) { // We can sell the stock
        //         profit = max(0 + dp[i + 1][1], prices[i] + dp[i + 1][0]);
        //     }

        //     dp[i][buy] = profit;
        //     }
        // }
        // return dp[0][0];