class Solution {
public:
    // int solve(string text1, string text2,int first,int second,vector<vector<int>>&dp){
    //     //MEMOIZATION
    //     if(first<0|| second<0){
    //         return 0;
    //     }

    //     if(dp[first][second]!=-1)return dp[first][second];

    //     if(text1[first]==text2[second]){
    //        return dp[first][second]=1+solve(text1,text2,first-1,second-1,dp);
    //     }else{
    //        return dp[first][second]=max(solve(text1,text2,first-1,second,dp),solve(text1,text2,first,second-1,dp));
    //     }
        
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m= text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));//shifting of index
        // return solve(text1,text2,n-1,m-1,dp);

        //TABULATION
       for(int i=0; i<=n;i++){
        dp[i][0]=0;
       }
         for(int i=0; i<=m;i++){
        dp[0][i]=0;
       }
        
        for(int first=1;first<=n;first++){
            for(int second=1;second<=m;second++){
        if(text1[first-1]==text2[second-1]){
          dp[first][second]=1+dp[first-1][second-1];
        }else{
           dp[first][second]=max(dp[first-1][second],dp[first][second-1]);
        }

            }
        }
        return dp[n][m];
    }
};