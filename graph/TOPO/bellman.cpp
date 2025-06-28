class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto& it : edges) {
                int a = it[0], b = it[1], w = it[2];
                if (dist[a] != 1e9 && dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                }
            }
        }

        // Optional: Check for negative weight cycle
        // Uncomment if needed
        /*
        for (auto& it : edges) {
            int a = it[0], b = it[1], w = it[2];
            if (dist[a] != 1e9 && dist[b] > dist[a] + w) {
                // Negative weight cycle detected
                return { -1 };
            }
        }
        */

        return dist;
    }
};
