class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n= s.length();
        int i=0;

        while(i<n){
            if(s[i]=='(' || s[i]== '{' || s[i]=='['){
                st.push(s[i]);
            }
            else {
                if(!st.empty()){
             if(s[i]=='}' && st.top()=='{' || (s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[')){
                st.pop();
            }else{
                return false;
            }
            }else{
                return false;
            }
            }
                i++;
        }

        return st.empty();
    }
};