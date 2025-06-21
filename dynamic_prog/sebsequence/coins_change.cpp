class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int>prev(amount+1,0);
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0)prev[i]=(i/coins[0]);
            else prev[i]=1e9;
        }
        for(int ind=1; ind<n;ind++ ){
        vector<int>cur(amount+1,0);
            for(int sum= 0;sum<=amount; sum++){
                int non_take= prev[sum];
                int take=1e9;
                if(coins[ind]<=sum) 
                take= 1+cur[sum-coins[ind]];
                cur[sum]=min(non_take,take);
            }prev=cur;
        }int ans= prev[amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};