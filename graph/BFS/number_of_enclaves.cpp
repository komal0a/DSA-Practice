class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>qt;
        for(int i=0; i<n;i++){
             if(grid[i][0]==1 ){
                vis[i][0]=1;
                qt.push({i,0});
             }
              if(grid[i][m-1]==1 ){
                vis[i][m-1]=1;
                 qt.push({i,m-1});
             }
        }

          for(int j=0;j<m;j++){
             if(grid[0][j]==1 ){
                vis[0][j]=1;
                 qt.push({0,j});
             }
              if(grid[n-1][j]==1 ){
                vis[n-1][j]=1;
                 qt.push({n-1,j});
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

             if(newi>=0 && newj>=0 && newi<n && newj<m && !vis[newi][newj] && grid[newi][newj]==1){
                    vis[newi][newj]=1;
                    qt.push({newi,newj});
                }
            }
        }

        int ans=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};