class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& vis,int row,int col,int color,int og_color){

         int n= image.size();
        int m= image[0].size();
         vis[row][col]=1;
         image[row][col]=color;

        int di[4]={1,0,-1,0};
        int dj[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nexti=row+di[i];
            int nextj=col+dj[i];

            if(nexti>=0 && nextj>=0 && nexti<n && nextj<m && image[nexti][nextj]==og_color && vis[nexti][nextj]==0){
                dfs(image,vis,nexti,nextj,color,og_color);
            }

        }
        }


    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
            int og_color=image[sr][sc];
    
                if(og_color!=color){
                    vis[sr][sc]=1;
                    image[sr][sc]=color;
                    dfs(image,vis,sr,sc,color,og_color);
                }

        return image;
    }
};