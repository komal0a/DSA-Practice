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

        long long mini=0;
        for(int i=0;i<n;i++){
         long long left = i - pse[i];
            long long right = nse[i] - i;
              mini = (mini + (left * right * arr[i]) ) ;
        }
        return mini;
    }

     int sumSubarrayMaxi(vector<int>& arr) {
        int n= arr.size();
        vector<int>nge(n,n);
        vector<int>pge(n,-1);
        stack<int>st;
        int mod=1e9+7;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            nge[i]= st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();

         for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }

            pge[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }   

        long long maxi=0;
        for(int i=0;i<n;i++){
         long long left = i - pge[i];
            long long right = nge[i] - i;
            maxi = maxi + (left * right * arr[i]);
        }
        return maxi;
    }
    long long subArrayRanges(vector<int>& nums) {
        
       return sumSubarrayMaxi(nums)-sumSubarrayMins(nums);
    }
};