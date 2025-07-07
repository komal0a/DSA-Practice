class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>>ans;
            if(intervals.size()==0){
                return ans;
            }
            sort(intervals.begin(),intervals.end());
            int n= intervals.size();
            vector<int>ds=intervals[0];

            for(auto& it: intervals){
                if(it[0] <= ds[1]){
                    ds[1]=max(ds[1],it[1]);
                }else{
                    ans.push_back(ds);
                    ds=it;
                }   
            }   

            ans.push_back(ds);    
            return ans;      
    }
};