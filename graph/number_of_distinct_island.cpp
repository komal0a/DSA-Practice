class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int baseRow, int baseCol, vector<pair<int, int>> &shape) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol}); // relative position

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid, vis, baseRow, baseCol, shape);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, vis, i, j, shape);
                    st.insert(shape); // store unique shape
                }
            }
        }

        return st.size(); // number of distinct islands
    }
};
