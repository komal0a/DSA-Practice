class Solution {
public:
    int func(vector<int>& bloomDay, int m,int mid, int k){
        int maxi=0;
            int cnt=0;
            vector<bool>adj;
            int i=0;
        for(int it:bloomDay){
            i=1;
            if(it<=mid){
                cnt++;//flower bloomed
            }else{
                maxi+=cnt/k;
                cnt=0;
            }
            i++;
        }
            maxi+=cnt/k;
        if(maxi>=m){
            return 1;//h=mid-1;
        }
        return 0;//l=mid+1;, need more flowers to blooom
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        int n= bloomDay.size();

        if(val>n)return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end()); int h=*max_element(bloomDay.begin(),bloomDay.end());

        while(l<=h){
            int mid=l+(h-l)/2;
            int midn=func(bloomDay,m,mid,k);
            if(midn==1){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};