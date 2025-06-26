 bool isCycle(int V, vector<int> adj[]) {
        

        vector<int>vis(V,0);

        // for(int i=0; i<V;i++){
        // if(!vis[i]){
        //     if(dfs(adj,vis,i,-1))return true;//node,parent
        //  }

        // }
        
        
        for(int i=0; i<V;i++){
        if(!vis[i]){
        queue<pair<int,int>>qt;
        qt.push({i,-1});
        vis[i]=1;
        while(!qt.empty()){
            int node= qt.front().first;
            int parent=qt.front().second;
            qt.pop();
           
                for(auto &it:adj[node]){
                    if(vis[it]==0){
                        vis[it]=1;
                        qt.push({it,node});
                    }
                    else if(it!=parent){
                        return true;
                    }
                 }
                }
            }
        }
        return false;
    }
};