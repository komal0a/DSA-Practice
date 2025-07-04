class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // sort greed factors
        sort(s.begin(), s.end());  // sort cookie sizes

        int i = 0; // pointer for children (greed)
        int j = 0; // pointer for cookies
        int cnt = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                cnt++; // child i gets cookie j
                i++;
                j++;
            } else {
                j++; // try next bigger cookie
            }
        }

        return cnt;
    }
};
