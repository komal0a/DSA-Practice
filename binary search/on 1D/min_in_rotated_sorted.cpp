class Solution {
public:
    int findMin(vector<int>& nums) {
       int n= nums.size();
        int l=0; int r=n-1;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
      

            if(nums[l]<=nums[mid]){
                //left is sorted
                ans=min(ans,nums[l]);
                l=mid+1;
            }else{
                // right is sorted
                  ans=min(ans,nums[mid]);
                  r=mid-1;
            }
        }
        return ans;
    }
};