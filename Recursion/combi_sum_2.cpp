//leetcode-40 , combination sum-2
class Solution {
public:
    void solve(vector<int>&candidates,int n, int i, int target,vector<int>&temp, vector<vector<int>>&ans){

         if (target == 0) {
            ans.push_back(temp);
           return;
         }

        for(int j=i; j<n;j++){
            if(j>i && candidates[j]==candidates[j-1])continue;//j>i is so that the we do not skip same element of different levels
            if(candidates[j]<=target){
                temp.push_back(candidates[j]);
                solve(candidates,n,j+1,target-candidates[j],temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n= candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
        solve(candidates,n,0,target,temp,ans);

        return ans;
    }
};