//36 leetcode validate sudoku
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
    bool solve(vector<vector<char>>&board){
        for(int i=0; i<9;i++){
            for(int j=0; j<9;j++){
                if(board[i][j]!='.'){
                    char ch=board[i][j];
                    board[i][j]='.';//temporarily clear the board and check if it has the number;
                    if(!issafe(i,j,ch,board)){
                       return false;
                    }
                    board[i][j]=ch;
                }
            }
        }return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       return solve(board);
    }
};