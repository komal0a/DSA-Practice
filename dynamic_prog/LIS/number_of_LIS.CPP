class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int>count(n,1);
        int maxi = 1;

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (arr[i]>arr[j] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    count[i]=count[j];
                }else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j]; // add count
                }
            }
            maxi=max(maxi,dp[i]);
      }

      int ans=0;
      for(int i=0; i<n;i++){
        if(dp[i]==maxi) ans+=count[i];
      }
      return ans;
    }
};