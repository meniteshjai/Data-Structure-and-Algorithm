class Solution {
public:

    bool find_empty(vector<vector<char>>& board,int &row,int &col){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row=i,col=j;
                    return true;
                }
            }
        }
        return false;
    }

    bool is_safe(vector<vector<char>>& board,int row,int col,char num){
        // check current row
        for(int j=0;j<9;j++){
            if(board[row][j]==num){
                return false;
            }
        }
        // check current col
        for(int i=0;i<9;i++){
            if(board[i][col]==num){
                return false;
            }
        }
        // check current box
        int start_row=row-(row%3);
        int start_col=col-(col%3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int r=i+start_row;
                int c=j+start_col;
                if(board[r][c]==num){
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        // find empty box.
        int row,col;
        if(!find_empty(board,row,col)){
           return true;
        }

        // fill with a suitable number.
        for(int i=1;i<=9;i++){
            char num=i+'0';
            if(is_safe(board,row,col,num)){
                board[row][col]=num;
                if(solve(board)){
                    return true;
                }
                board[row][col]='.'; // backtrack
            }
        }
        // not able to put any number from 1 to 9
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};