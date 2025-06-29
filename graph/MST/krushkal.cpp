class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
     vector<int>vis(V,0);

     //pq
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
     pq.push({0,0});//weight,to
     int sum=0;
    vector<int>mst(V);
     while(!pq.empty()){
        int weight=pq.top().first;
        int to= pq.top().second;
       
        pq.pop();
        if(vis[to])continue;
        vis[to]=1;
    
        sum+=weight;

        for(auto& it:adj[to]){
            int wt=it[1];
            int next=it[0];

            if(!vis[next]){
                pq.push({wt,next});
            }

        }
     }  

        return sum;
    }
};
