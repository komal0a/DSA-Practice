class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>arr(26,0);
        int n= s.length();
        int l=0; int r=0;
        int maxlength=0;
        int maxi=0;
        while(r<n){
          arr[s[r]-'A']++;       
          maxi=max(maxi,arr[s[r]-'A']);
          if((r-l+1)-maxi >k){
             arr[s[l]-'A']--;
             l++;
          }
          maxlength=max(maxlength,r-l+1);
          r++;
        }
        return maxlength;
    }
};