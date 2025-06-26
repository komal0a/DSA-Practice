class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
       int i = 0;
for (auto& it : graph) {
    if (!it.empty()) {
        for (int j = 0; j < it.size(); j++) {
            int v = it[j];
            adj[v].push_back(i);      // reverse the edge
            indegree[i]++;            // count out-degree of i in original graph
        }
    }
    i++; // ✅ increment after processing each node
}


        queue<int>qt;
        for(int i=0; i<n;i++){
           if( indegree[i]==0){
                qt.push(i);
            }
        }

        vector<int>ans;
        while(!qt.empty()){
            int node=qt.front();
            qt.pop();
            ans.push_back(node);

            for(auto& it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)qt.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};