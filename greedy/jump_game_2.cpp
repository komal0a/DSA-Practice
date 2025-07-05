class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();

        int steps=0;
        int l=0; int r=0;

        while(r<n-1){
          int maxreach=0;
            for(int j=l ; j<=r;j++){
                maxreach=max(maxreach,j+ nums[j]);
            }
                l=r+1;
                r=maxreach;
                steps++;
        }
        return steps;
    }   
};