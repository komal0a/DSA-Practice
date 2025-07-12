class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        // Your code goes here
         int n=arr.size();
         vector<int>ans(n,-1);
         stack<int>st;

         for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=st.top() ){
                st.pop();
            }
        
            ans[i]= st.empty() ? -1 : st.top();
            st.push(arr[i]);    
        }


         return ans;
    }
};
