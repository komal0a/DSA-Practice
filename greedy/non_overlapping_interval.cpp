class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=1;
        int last=intervals[0][1];

        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=last){
                cnt++;
                last=intervals[i][1];
            }
        }

        return n-cnt;
    }
};