//leetcode 139 word break
class Solution {
public:
    bool solve(string s, unordered_set<string> &dict,int idx,int n,vector<int>&dp){
    if(idx==n)return true;
        if(dp[idx]!=-1)return dp[idx];

       for(int j=idx;j<n;j++){
        string temp=s.substr(idx,j-idx+1);
        if(dict.count(temp)){
               if(solve(s,dict,j+1,n,dp)) return dp[idx]=true;
            }
        }
       
       return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int>dp(n,-1);
       return solve(s,dict,0,n,dp);
        
    }
};