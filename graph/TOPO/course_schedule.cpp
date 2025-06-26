class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
for (auto& v : prerequisites) {
    int a = v[0];
    int b = v[1];
    adj[b].push_back(a); // b → a (b must be done before a)
}

     

     vector<int>indegree(numCourses,0);
      for(int i=0;i<adj.size();i++){
     for(auto & it:adj[i]){
      indegree[it]++;
      //filled indegree
     }   
     }

    queue<int>qt;
    for(int i=0; i<indegree.size();i++){
        if(indegree[i]==0){
            qt.push(i);
        }
    }

    vector<int>ans;
    while(!qt.empty()){
        int node= qt.front();
        qt.pop();
        ans.push_back(node);

        for(auto& it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)qt.push(it);
        }
    }
    return (ans.size()==numCourses);
    }
};
