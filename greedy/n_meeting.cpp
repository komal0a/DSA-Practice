
class Solution{
    public:
    static bool comp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here

        vector<pair<int,int>>item;

        for(int i=0; i<start.size() ;i++){
            item.push_back({start[i],end[i]});
        }

        sort(item.begin(),item.end(),comp);

        int cnt=1;
        int last=item[0].second;
        for(int i=1; i<start.size() ;i++){
            if(item[i].first>last){
                cnt++;
                last=item[i].second;
            }
        }
        return cnt;
    }
};