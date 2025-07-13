class Solution {
public:

 int first(vector<int> &nums, int x){
        int n= nums.size();
        int l=0; int h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==x){
                ans=mid;
                h=mid-1;
            }
            else if(nums[mid]>x){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }

     int last(vector<int> &nums, int x){
        int n= nums.size();
        int l=0; int h=n-1;
        int ans=-1;
        while(l<=h){
           int mid=(l+h)/2;
            if(nums[mid]==x){
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]>x){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int x) {
        vector<int>ans(2,-1);

       ans[0] = first(nums, x);
        ans[1] = last(nums, x);

        return ans;
    }
};