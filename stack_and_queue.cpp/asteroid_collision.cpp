class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        int n=asteroids.size();

        for(int i=0; i<n ;i++){
            if( asteroids[i]<0){
                //negative
                
              while(!st.empty() && st.top()>0 && abs(asteroids[i]) > st.top()){
                st.pop();
                }
              
                if(!st.empty() &&  abs(asteroids[i]) == st.top()){
                    st.pop();
                 } 
                 else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                 }
              }
            
            else{
                st.push(asteroids[i]);
            }

        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};