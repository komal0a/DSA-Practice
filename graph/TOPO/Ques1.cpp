class Solution{
public:
    void dfs(vector<int>adj[],int node,stack<int>&st,vector<int>&vis){
    vis[node]=1;
    for(auto& it:adj[node]){
    if(!vis[it]){
        dfs(adj,it,ans,vis);
    }
    }
        st.push(node);

    }
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int>vis(V,0);
    stack<int>st;
        for(int i=0; i<V;i++){
            if(!vis[i]){
                  dfs(adj,i,st,vis);
            }
        }

        vector<int>ans;
         while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

        return ans;
    }
};

