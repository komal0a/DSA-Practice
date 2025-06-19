//rat in a maze
class Solution{
    public:
    int n;
    void solve(vector<vector<int>>&grid,int dx[],int dy[],string& ch,int row,int col,string temp,vector<string>&ans, vector<vector<int>>&visited){
        if(row==0 && col==0){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }

        visited[row][col]=1;
        for(int i=0; i<4;i++){
            int nexti=row+dx[i];
            int nextj=col+dy[i];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && visited[nexti][nextj]==0 && grid[nexti][nextj]==1){

                solve(grid,dx,dy,ch,nexti,nextj,temp+ch[i],ans,visited);
                
            }

        }
        visited[row][col]=0;
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        n= grid.size();
        if(grid[0][0]==0 || grid[n-1][n-1]==0)return {};
        //your code goes here

        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};
        string ch="DLRU";
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        solve(grid,dx,dy,ch,n-1,n-1,"",ans,visited);
        return ans;
    }
};