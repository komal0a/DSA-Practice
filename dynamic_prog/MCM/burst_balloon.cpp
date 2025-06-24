class Solution {
public:
//     int f(vector<int>& nums,vector<vector<int>>& dp, int i,int j){
//         if(i>j)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int maxi=INT_MIN;
//         for(int k=i; k<=j;k++){
//             int cost=nums[i-1]*nums[k]*nums[j+1]+f(nums,dp,i,k-1)+f(nums,dp,k+1,j);
//             maxi=max(maxi,cost);
//         }
//         return dp[i][j]=maxi;
//     }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        // return f(nums,dp,1,n);

         vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>0;i--){
            for(int j=i;j<=n;j++){
                int maxi=INT_MIN;
                 for(int k=i; k<=j;k++){
                    int cost=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                      maxi=max(maxi,cost);
                  }
                      dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};