class Solution {
public:
const int prime = 1e9 + 7;
    // int solve(string s, string t, int i, int j,vector<vector<int>>&dp){
    //     //MEMOIZATION
    //     if(j<0)return 1;
    //     if(i<0)return 0;

    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i]==t[j]){
    //         return dp[i][j]=solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
    //     }else{
    //         return dp[i][j]=solve(s,t,i-1,j,dp);
    //     }
    // }
    int numDistinct(string s, string t) {
        int n= s.length();
        int m= t.length();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(s,t,n-1,m-1,dp);
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //TABULATION

        for(int i=0; i<=n;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j] )% prime;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};