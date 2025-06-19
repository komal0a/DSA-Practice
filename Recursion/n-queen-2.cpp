//n-queen-52 leetcode
class Solution {
 public:
    void solve(int col,vector<int>&column,vector<int>&upperdiagonal,vector<int>&lowerdiagonal, int &ans,vector<string>&board,int n){

            if(col==n){
                ans++;
                return;
            }

            for(int row=0; row<n;row++){
                if(column[row]==0 && upperdiagonal[n-1+col-row]==0 && lowerdiagonal[row+col]==0){
                    board[row][col]='Q';
                    column[row]=1;
                    lowerdiagonal[row+col]=1;
                    upperdiagonal[n-1+col-row]=1;
                    solve(col+1,column,upperdiagonal,lowerdiagonal,ans,board,n);
                     board[row][col]='.';
                    column[row]=0;
                    lowerdiagonal[row+col]=0;
                    upperdiagonal[n-1+col-row]=0;
                }
            }
    }
public:
    int totalNQueens(int n) {
       int ans=0;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        vector<int>column(n,0);
        vector<int>upperdiagonal(2*n-1,0);vector<int>lowerdiagonal(2*n-1,0);
        solve(0,column,upperdiagonal,lowerdiagonal,ans,board,n);

        return ans;
    }
};
