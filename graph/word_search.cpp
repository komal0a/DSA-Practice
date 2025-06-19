//leetcode-79 word search
class Solution {
public:
    void solve(vector<vector<char>>& board, string word,int n, int m,bool& ans,int row,int col,vector<vector<int>>&vis,int i){
        if(i==word.size()){
            ans=true;
            return;
        }

        if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col] || board[row][col] != word[i]) return;

        vis[row][col] = 1;

        // Explore all 4 directions
        solve(board, word, n, m, ans, row + 1, col, vis, i + 1);
        solve(board, word, n, m, ans, row - 1, col, vis, i + 1);
        solve(board, word, n, m, ans, row, col + 1, vis, i + 1);
        solve(board, word, n, m, ans, row, col - 1, vis, i + 1);

        vis[row][col] = 0; // Backtrack

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        int n=board.size();
        int m= board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    solve(board,word,n,m,ans,i,j,vis,0);
                    if(ans) return true;
                }
            }
        }
        return ans;
    }
};