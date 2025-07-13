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

     int floor(vector<int> &nums, int x){
        int n= nums.size();
        int l=0; int h=n-1;
        int ans=n;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]<=x){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
          vector<int> ans;
        sort(nums.begin(), nums.end()); // in case array isn't sorted

        int floorIndex = floor(nums, x);
        int ceilIndex = lowerBound(nums, x);

        ans.push_back(floorIndex != -1 ? nums[floorIndex] : -1);
        ans.push_back(ceilIndex != nums.size() ? nums[ceilIndex] : -1);

        return ans;
    }
};