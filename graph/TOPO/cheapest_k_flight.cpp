class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        vector<vector<pair<int, int>>> adj(n); // ✅ fixed

        for (auto& it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> qt; // {price, {node, stops}}
        qt.push({0, {src, 0}});
        dist[src] = 0;

        while (!qt.empty()) {
            int price = qt.front().first;
            int node = qt.front().second.first;
            int stop = qt.front().second.second;
            qt.pop();

            if (stop > k) continue;

            for (auto& it : adj[node]) {
                int dn = it.first;
                int wt = it.second;

                if (price + wt < dist[dn]) {
                    dist[dn] = price + wt;
                    qt.push({dist[dn], {dn, stop + 1}}); // ✅ fixed
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
