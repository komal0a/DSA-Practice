//leetcode 213 house robber-2
//follow up for house robber-1
class Solution {
public:
    int solve(vector<int>& nums){
        //space optimization
        int n= nums.size();
        
      int prev=nums[0];
      int prev2=0;
       for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
        take+=prev2;
        }
        int non_take=0+prev;

        int curi=max(take,non_take);
        prev2=prev;
        prev=curi;
     }
        return prev;
    }
    int rob(vector<int>& nums) {
      int n= nums.size();
      if(n==0)return 0;
        if(n==1)return nums[0];
      vector<int> arr1(nums.begin() + 1, nums.end());         // from index 1 to n-1
      vector<int> arr2(nums.begin(), nums.end() - 1);         // from index 0 to n-2

        return max(solve(arr1),solve(arr2));
    }
};