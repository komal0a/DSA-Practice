//leetcode 37-sudoku solver
class Solution {
public: 

    bool issafe(int row,int col, char ch,vector<vector<char>>&board){
        for(int i=0; i<9;i++){
            if(board[row][i]==ch){
                return false;//for col
            }

             if(board[i][col]==ch){
                return false;//for row
            }

            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==ch){
                return false;//for particular compartment
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(issafe(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board))return true;
                            board[i][j]='.';
                    }
                    }
                    return false;
                }
             }
         }
         return true;
    }
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
        
    }
};