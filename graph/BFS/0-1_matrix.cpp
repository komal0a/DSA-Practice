class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> qt;

        // Step 1: Push all 0s into queue, mark distance 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    qt.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        // Step 2: BFS from all 0s
        while (!qt.empty()) {
            int x = qt.front().first;
            int y = qt.front().second;
            qt.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    // If we found a shorter path
                    if (ans[newX][newY] > ans[x][y] + 1) {
                        ans[newX][newY] = ans[x][y] + 1;
                        qt.push({newX, newY});
                    }
                }
            }
        }

        return ans;
    }
};
