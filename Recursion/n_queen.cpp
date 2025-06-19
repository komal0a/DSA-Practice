//leetcode 51, n-queen

class Solution {
public:
    void solve(int col,vector<string>&board,vector<int>&left_row,vector<int>&upper_diagonal,vector<int>&lower_diagonal, vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n;row++){
            if(left_row[row]==0 && upper_diagonal[n-1+col-row]==0 && lower_diagonal[row+col]==0){
                board[row][col]='Q';
                left_row[row]=1;
                lower_diagonal[row+col]=1;
                upper_diagonal[n-1+col-row]=1;
                solve(col+1,board,left_row,upper_diagonal,lower_diagonal,ans,n);
                board[row][col]='.';
                left_row[row]=0;
                lower_diagonal[row+col]=0;
                upper_diagonal[n-1+col-row]=0;
            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board;
        string s(n,'.');
        for(int i=0; i<n;i++){
            board.push_back(s);
        }

        vector<int>left_row(n,0);vector<int>upper_diagonal(2*n -1,0);vector<int>lower_diagonal(2*n-1,0);

        solve(0,board,left_row,upper_diagonal,lower_diagonal,ans,n);
        return ans;
    }
};