//leetcode 22, generate parenthesis
class Solution {
public:
    void solve(int o, int c,vector<string>&ans,int n,string st){
        if(o==n && c==n){
            ans.push_back(st);
            return;
        }

        if(o<n){
            solve(o+1,c,ans,n,st+'(');
        }
        if(c<o){
            solve(o,c+1,ans,n,st+')');
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,ans,n,"");

        return ans;
    }
};