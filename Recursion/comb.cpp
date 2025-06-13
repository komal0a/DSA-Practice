//77 leetcode, combination
class Solution {
public:
    void solve(vector<int>&temp,vector<vector<int>>&ans,int n, int k,int i){
        if(temp.size()==k){
            ans.push_back(temp);return;
        }
        if(i>n){
            return;
        }

        temp.push_back(i);
        solve(temp,ans,n,k,i+1);
        temp.pop_back();
        solve(temp,ans,n,k,i+1);

        // // //for(int j=i;j<n;j++){
        //     temp.push_back(j);
        //     solve(temp,ans,n,k,j+1);
        //     temp.pop_back();
        // // }

    }
    vector<vector<int>> combine(int n, int k) {
     vector<int>temp;
     vector<vector<int>>ans;

     solve(temp,ans,n,k,1);
     return ans;
    }
};