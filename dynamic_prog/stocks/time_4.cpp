class Solution {
public:
//  int solve(vector<int>&arr,vector<vector<int>>& dp,int ind,int transaction){
//         if(transaction==0 || ind==arr.size())return 0;

//         if(dp[ind][transaction]!=-1)return dp[ind][transaction];

//         int profit=0;
//         if(transaction%2==0){
//             //buy
//             return dp[ind][transaction]=max(-arr[ind]+solve(arr,dp,ind+1,transaction-1),0+solve(arr,dp,ind+1,transaction));
//         }else{
//            return  dp[ind][transaction]=max(arr[ind]+solve(arr,dp,ind+1,transaction-1),0+solve(arr,dp,ind+1,transaction));
//         }
        
//     }
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        // vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
        // return solve(prices,dp,0,2*k);


        vector<int>prev(2*k+1,0);
        vector<int>cur(2*k+1,0);
        for(int ind=n-1;ind>=0;ind--){
        for(int trans=1;trans<=2*k;trans++){
             int profit=0;
        if(trans%2==0){
            //buy
            cur[trans]=max(-prices[ind]+prev[trans-1],0+prev[trans]);
        }else{
           cur[trans]=max(prices[ind]+prev[trans-1],0+prev[trans]);
        }

        }prev=cur;
        }
        return prev[2*k];
    }
};
//TABULATION
        //  vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

        // for(int ind=n-1;ind>=0;ind--){
        // for(int trans=1;trans<=2*k;trans++){
        //      int profit=0;
        // if(trans%2==0){
        //     //buy
        //      dp[ind][trans]=max(-prices[ind]+dp[ind+1][trans-1],0+dp[ind+1][trans]);
        // }else{
        //    dp[ind][trans]=max(prices[ind]+dp[ind+1][trans-1],0+dp[ind+1][trans]);
        // }

        // }
        // }
        // return dp[0][2*k];

        