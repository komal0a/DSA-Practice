class Solution {
public:
    int func(vector<int>& nums, int days,int weight){
        int temp=0;
        int cnt=1;
        for(int i=0; i<nums.size();i++){

           if(temp+nums[i]>weight) {
                cnt++;temp=0;
           }
            temp+=nums[i];
        }
        if(cnt<=days)return 1;
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
     int l= *max_element(weights.begin(),weights.end());
     int h= accumulate(weights.begin(), weights.end(), 0);
     while(l<=h){
        int mid=l+(h-l)/2;
        if(func(weights,days,mid)){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
     }
     return l;   
    }
};