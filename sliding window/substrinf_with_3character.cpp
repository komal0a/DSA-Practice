
class Solution {
public:
    int numberOfSubstrings(string s) {
            int l=0; int r=0; int n= s.length();
            int cnt=0;
            vector<int>vec(3,-1);

            while(r<n){
                vec[s[r]-'a']=r;
                    if(vec[0]!=-1 && vec[1]!=-1 && vec[2]!=-1){
                       int mini = min({vec[0], vec[1],vec[2]});

                        cnt+=mini+1;
                    }                
                r++;
            }

            return cnt;
    }
};