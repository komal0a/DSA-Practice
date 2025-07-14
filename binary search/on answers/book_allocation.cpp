class Solution {
public:
    int func(vector<int> &nums, int pages,int m){
        int cnt=1;
        int last=nums[0];
        for(int i=1; i<nums.size();i++){
            if(last+nums[i]>pages){
                cnt++;
                last=0;
            }
            last+=nums[i];
        }
        if(cnt<=m)return 1;//doesnot matter if a student is not given a book
        return 0;
    }
    int findPages(vector<int> &nums, int m)  {
        if(nums.size()<m)return -1;
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(nums,mid,m)){
                ans=mid;
                h=mid-1;
            }
                l=mid+1;
        }
        return ans;
    }
};