class Solution {
public:
  int findMin(vector<int>& nums) {
       int n= nums.size();
        int l=0; int r=n-1;
        int ans=INT_MAX;
        int index=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
      
              if (nums[l] <= nums[r]) {
                if (nums[l] < ans) {
                    ans = nums[l];
                    index = l;
                }
                break;  // Entire segment is sorted, no need to continue
            }
            
            if(nums[l]<=nums[mid]){
                //left is sorted
               
                if(ans>nums[l]){
                    index=l;
                    ans=nums[l];
                }
              
                l=mid+1;
            }else{
                // right is sorted
                 if(ans>nums[mid]){
                    index=mid;
                    ans=nums[mid];
                }
              
                  r=mid-1;
            }
        }
        return index;
    }
    int findKRotation(vector<int> &nums)  {
        return findMin(nums);
    }
};