//47. permutation-2
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 
class Solution {
public:
    unordered_set<int>st;
    void solve(vector<vector<int>>&ans,vector<int>&temp, vector<int>&nums,int n,vector<bool>&used){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(used[j])continue;

            if(j>0 && nums[j]==nums[j-1] && !used[j-1])continue;

                temp.push_back(nums[j]);
               used[j]=true;
                solve(ans,temp,nums,n,used);
                temp.pop_back();
                 used[j]=false;
            }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<bool>used(n,false);

        solve(ans,temp,nums,n,used);
        return ans;
    }
};