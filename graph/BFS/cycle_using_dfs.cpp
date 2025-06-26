class Solution{
public:

    bool dfs( vector<int> adj[],vector<int>&vis,int i,int parent){
        vis[i]=1;
        for(auto &it:adj[i]){
            if(vis[it]==0){
                if(dfs(adj,vis,it,i))return true;            
            } else if(it!=parent){//it is visited
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        

        vector<int>vis(V,0);

        for(int i=0; i<V;i++){
        if(!vis[i]){
            if(dfs(adj,vis,i,-1))return true;//node,parent
         }

        }
        return false;
    }
};

//use parent node whenever we want to find a cycle in undirected graph