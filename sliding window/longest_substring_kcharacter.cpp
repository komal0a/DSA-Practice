class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        unordered_map<char,int>mp;

        int l=0; int r=0; int n= s.length();
        int maxlength=0;

        while(r<n){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            maxlength=max(maxlength,r-l+1);
        r++;
        }
        return maxlength;
    }
};