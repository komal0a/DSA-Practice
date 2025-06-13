//216 leetcode, combination sum-3
class Solution {
public:
    void solve(vector<int>&temp,vector<vector<int>>&ans,int size, int target,int i){
            if(target==0 &&  temp.size()==size){
            ans.push_back(temp);
            return;
         }

        for(int j=i;j<10;j++){
            if(j<=target){
                temp.push_back(j);
                solve(temp,ans,size,target-j,j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
         
         solve(temp,ans,k,n,1);
         return ans;
    }
};