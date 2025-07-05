class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        int ans=1;int cnt=1;
        int i=0; int j=0;

        while(i<n && j<n){
            if(Arrival[i]<=Departure[j]){
                i++;
                cnt++;
            }else{
                cnt--;
                j++;//departure
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};