class Solution {
public:
     static bool comp(string & s1,string& s2){
        return s1.size()<s2.size();
    }

    bool check(string& s1, string& s2){
        if(s1.size()!=s2.size()+1)return false;//because s1 is larger in  length
        int one=0; int two=0;
        while(one<s1.size()){
            if(s1[one]==s2[two]){
                one++;
                two++;
            }else{
                one++;
            }

        }
            if(one==s1.size() && two==s2.size())return true;
            else return false;

    }
    int longestStrChain(vector<string>& words) {
        //we want to form subset
        sort(words.begin(),words.end(),comp);
        int n= words.size();

        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0; i<n;i++){
            for(int j=0; j<i;j++){
                if(check(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];

                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }

        return maxi;
    }
};