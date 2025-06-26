class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
          int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>distance(n,vector<int>(m,1e9));

        // if(grid[0][0]==0)return -1;

        //min-heap
        priority_queue<
    pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
   
        pq.push({0,{0,0}});//dist,row,col

        distance[0][0]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1)return dist;
            int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};

            for(int i=0; i<4;i++){
                int nx=row+dx[i];
                int ny= col+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m ){
                    int effort = max(dist, abs(grid[nx][ny] - grid[row][col]));
                        if (effort < distance[nx][ny]) {
                            distance[nx][ny] = effort;
                            pq.push({effort, {nx, ny}});
                        }
                }
            }
        }
        return -1;
    }
};