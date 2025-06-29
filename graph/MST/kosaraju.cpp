class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto &it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for (auto &it : adj[node]) {
            if (!vis[it]) {
                dfs3(it, adj, vis);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        // 1. Topo sort using DFS
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // 2. Transpose the graph
        vector<int> transpose[V];
        for (int i = 0; i < V; i++) {
            for (auto &it : adj[i]) {
                transpose[it].push_back(i);
            }
        }

        // 3. DFS on transposed graph
        fill(vis.begin(), vis.end(), 0);
        int cnt = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!vis[node]) {
                cnt++;
                dfs3(node, transpose, vis);
            }
        }

        return cnt;
    }
};
