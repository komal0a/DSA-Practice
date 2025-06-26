class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>distance(n,vector<int>(m,1e9));

        if(grid[0][0]!=0)return -1;

        //min-heap
        priority_queue<
    pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        pq.push({1,{0,0}});//dist,row,col

        distance[0][0]=1;
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1)return dist;
            int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

            for(int i=0; i<8;i++){
                int nx=row+dx[i];
                int ny= col+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0){
                    if(distance[nx][ny]>dist+1){
                        distance[nx][ny]=dist+1;
                        pq.push({dist+1,{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};