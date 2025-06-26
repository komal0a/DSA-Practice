class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int>dist(V,1e9);
        vector<int>parent(V);
        for(int i=0; i<V;i++){
            parent[i]=i;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        //min-heap
        pq.push({0,S});//distance,node
        dist[0]=0;

        while(!pq.empty()){
            int node= pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto& it:adj[node]){
                int v=it[0];
                int wt=it[1];
                if(distance+wt<dist[v]){
                    dist[v]=distance+wt;
                    parent[v]=node;
                    pq.push({dist[v],v});
                }
            }
        }   
        if(dist[V-1]==1e9)return{-1};

        vector<int>ans;
        int node=V-1;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(S);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};