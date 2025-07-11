class Solution {
public:
    int lengthOfLongestSubstring(string s) {
              unordered_set<char>st;
              int n= s.length();
              int maxlength=0;

              int l=0; int r=0;
              while(r<n){
                if(st.find(s[r]) == st.end()){
                    st.insert(s[r]);
                    maxlength=max(maxlength,r-l+1);
                    r++;
                }else{
                    st.erase(s[l]);
                    l++;
                }
              }

              return maxlength;
    }
};