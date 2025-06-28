class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto it:roads){
            long long v= it[1];
            long long u = it[0];
            long long w= it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
                    }
       priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

      vector<long long>ways(n,0),ans(n,LONG_MAX);
      pq.push({0,0});
      ways[0]=1;
      ans[0]=0;
      long long mod= 1e9+7;
      while(!pq.empty()){
        long long wa= pq.top().first;
        long long node= pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            long long newnode= it.first;
            long long weight= it.second;
            if(wa+weight<ans[newnode]){
                ans[newnode]= wa+ weight;
                ways[newnode]= ways[node];
                 pq.push({ans[newnode],newnode});
            }
            else if(wa+weight==ans[newnode]){
                ways[newnode]=(ways[newnode]+ways[node])%mod;
            }
        }
      }
         return ways[n-1]%mod;
    }
};