class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>freq(26);

        for(auto &it:tasks){
            freq[it-'A']++;
        }

        sort(freq.begin(),freq.end());

        int max_freq=freq[25];
        int gaddhe=max_freq-1;
        int idealslots=gaddhe*n;

        for(int i=24; i>=0 && freq[i]>0 ;i--){
            idealslots-=min(gaddhe,freq[i]);
        }

        return idealslots > 0 ? tasks.size() +idealslots : tasks.size()  ; 
    }
};