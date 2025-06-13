//leetcode-39. combination in recursion
class Solution {
public:int n;

    void solve(vector<int>&candidates,int target,int i, vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n || target<0){
            return;
        }
       
            if(candidates[i]<=target){
            temp.push_back(candidates[i]);
             solve(candidates,target-candidates[i],i,temp,ans);
             temp.pop_back();
            }

            solve(candidates,target,i+1,temp,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n= candidates.size();
        vector<int>temp;
        vector<vector<int>>ans;
        solve(candidates,target,0,temp,ans);
        return ans;
    }
};