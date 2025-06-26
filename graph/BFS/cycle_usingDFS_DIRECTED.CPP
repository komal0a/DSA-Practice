class Solution{
public:
    bool dfs(vector<int> adj[],int node, vector<int>&vis, vector<int>&pathvis ){
        vis[node]=1;
        pathvis[node]=1;
        for(auto& it:adj[node]){
            if(!vis[it]){
            if(dfs(adj,it,vis,pathvis))return true;
            }
            else if(pathvis[it]==1)return true;
        }
            pathvis[node]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);

        for(int i=0; i<v;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,pathvis))return true;
            }
        }
        return false;
    }
};

//    vector<int>indegree(V,0);

//     for(int i=0;i<V;i++){
//     for(auto &it:adj[i]){
//         indegree[it]++;
//         //filling indegree array
//     }
//     }       

//     queue<int>qt;
//     for(int i=0; i<V;i++){
//         if(indegree[i]==0){
//             qt.push(i);
//             //pushed initial nodes
//         }
//     }
//     vector<int>ans;
//     while(!qt.empty()){
//         int node = qt.front();
//         qt.pop();
//         ans.push_back(node);

//         for(auto& it:adj[node]){
//             indegree[it]--;
//             if(indegree[it]==0){
//                 qt.push(it);
//             }
//         }
//     }
//         return (ans.size()==V);