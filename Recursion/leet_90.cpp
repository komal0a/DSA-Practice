class Solution {
public:
    void recur(vector<int>&nums,int i, int n, vector<int>&first,vector<vector<int>>&ans){
        if(i==n){ans.push_back(first);return;}

        first.push_back(nums[i]);
        recur(nums,i+1,n,first,ans);
        first.pop_back();

        int idx=i+1;
        while(idx<n && nums[i]==nums[idx]){
            idx++;
        }
        recur(nums,idx,n,first,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>first;
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        recur(nums,0,n,first,ans);
        return ans;
    }
};//subset-2 without duplicate