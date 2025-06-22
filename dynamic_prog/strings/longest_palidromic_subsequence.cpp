class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //it is finding lcs between s and reverse(s);;
        //TABULATION
        string text2=s;
        reverse(text2.begin(),text2.end());
         int n=s.size();
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
        if(s[first-1]==text2[second-1]){
          dp[first][second]=1+dp[first-1][second-1];
        }else{
           dp[first][second]=max(dp[first-1][second],dp[first][second-1]);
        }

            }
        }
        return dp[n][m];
    }
};