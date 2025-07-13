class Solution {
public:
 int lowerBound(vector<int> &nums, int x){
        int n= nums.size();
        int l=0; int h=n-1;
        int ans=n;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>=x){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
         int l=0;
        int n= nums.size();
        int h=n-1;

        while(l<=h){
        int mid=l+(h-l)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return lowerBound(nums,target);
    }
};