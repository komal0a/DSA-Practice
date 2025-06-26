bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1); // -1 means uncolored

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node]; // alternate color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // adjacent same color → not bipartite
                    }
                }
            }
        }
    }
    return true;
}
