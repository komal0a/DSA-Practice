class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        stack<int>st;
        int mod=1e9+7;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse[i]= st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();

         for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            pse[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }   

        long long ans=0;
        for(int i=0;i<n;i++){
         long long left = i - pse[i];
            long long right = nse[i] - i;
              ans = (ans + (left * right % mod * arr[i]) % mod) % mod;
        }
        return ans;
    }
};