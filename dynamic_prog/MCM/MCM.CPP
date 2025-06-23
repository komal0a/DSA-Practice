class Solution{
	public:
        // int f(int i,int j,  vector<vector<int>>&dp,vector<int>& nums){

        //     if(i==j )return 0;
        //     //MEMOIZATION
        //     if(dp[i][j]!=-1)return dp[i][j];
        //     int mini=1e9;
        //     for(int k=i;k<j;k++){
        //         int steps=nums[i-1]*nums[k]*nums[j]+f(i,k,dp,nums)+f(k+1,j,dp,nums);
        //         if(steps<mini)mini=steps;
                
        //     }
        //     return mini;
        // }
		int matrixMultiplication(vector<int>& nums){
            //your code goes here
            int n= nums.size();
            // return f(1,n-1,dp,nums);
            vector<vector<int>>dp(n,vector<int>(n,0));
            //TABULATION
            for(int i=0;i<n;i++){
                dp[i][i]=0;
            }

            for(int i=n-1;i>=1;i--){
                for(int j=i+1;j<n;j++){
                    int mini=1e9;
                    for(int k=i;k<j;k++){
                int steps=nums[i-1]*nums[k]*nums[j]+dp[i][k]+dp[k+1][j];
                if(steps<mini)mini=steps;
                
            }
             dp[i][j]=mini;
                }
            }
            return dp[1][n-1];
    	}
};