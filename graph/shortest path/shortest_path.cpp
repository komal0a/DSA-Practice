class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M) {
        vector<int> adj[N];

        // Build adjacency list
        for (auto& it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }

        vector<int> dist(N, INT_MAX);
        queue<pair<int, int>> qt;
        qt.push({0, 0});
        dist[0] = 0;

        while (!qt.empty()) {
            int node = qt.front().first;
            int dis = qt.front().second;
            qt.pop();

            for (auto& it : adj[node]) {
                if (dist[it] > dis + 1) {
                    dist[it] = dis + 1;
                    qt.push({it, dis + 1});
                }
            }
        }

        // Optional: mark unreachable nodes with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
