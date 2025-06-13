//leetcode 90 subset_2
class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int i, int n){
       ans.push_back(temp);
       
        for(int j=i; j<n;j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }

            temp.push_back(nums[j]);
            solve(ans,temp,nums,j+1,n);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int n= nums.size();
     vector<int>temp;
     vector<vector<int>>ans;

     solve(ans, temp,nums,0,n);
     return ans;   
    }
};