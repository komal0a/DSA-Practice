class Solution {
public:
    void recur(vector<int>&nums,int i,int n,vector<int>&small, vector<vector<int>>&ans){
        if(i>=n){
        ans.push_back(small);
        return;
    }


        small.push_back(nums[i]);
        recur(nums,i+1,n,small,ans);
        small.pop_back();
        recur(nums,i+1,n,small,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>small;  
        vector<vector<int>>ans;
        int n= nums.size();
        recur(nums,0,n,small,ans);
        return ans;
    }
};//leetcode-78