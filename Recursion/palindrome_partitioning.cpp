// //131. Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:
// Input: s = "a"
// Output: [["a"]]
class Solution {
public:
    int n;
    bool ispalindrome(string& s , int start, int end){
        while(start<end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }

    void solve(vector<string>&temp,vector<vector<string>>&ans,string s, int i){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<n;j++){
            if(ispalindrome(s,i,j)){
            temp.push_back(s.substr(i, j - i + 1));
            solve(temp,ans,s,j+1);
            temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        n= s.length();

        solve(temp,ans,s,0);
        return ans;
    }
};