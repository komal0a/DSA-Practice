class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>qt;
       for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                vis[0][j] = 1;
                qt.push({0, j});
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                vis[n - 1][j] = 1;
                qt.push({n - 1, j});
            }
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                vis[i][0] = 1;
                qt.push({i, 0});
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                vis[i][m - 1] = 1;
                qt.push({i, m - 1});
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        
        while(!qt.empty()){
            int row=qt.front().first;
            int col=qt.front().second;

            qt.pop();

            for(int i=0 ;i<4;i++){
                int newi=row+dx[i];
                int newj=col+dy[i];

                if(newi>=0 && newj>=0 && newi<n && newj<m && !vis[newi][newj] && board[newi][newj]=='O'){
                    vis[newi][newj]=1;
                    qt.push({newi,newj});
                }
            }
        }
            
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }                
            }
        }
      }
};