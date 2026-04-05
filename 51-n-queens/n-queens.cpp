class Solution {
public:
vector<vector<string>> result;
int N;
    bool isValid(vector<string> & board,int row,int col){
        //look up
        for (int i = row-1;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //look left up diag;
        for(int i = row-1,j = col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        // lool right up diag 
        for(int i = row-1,j = col+1;i>=0 && j<N;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> & Board, int row){
        if(row>=N){
            result.push_back(Board);
            return;
        }
        for(int col = 0;col<N;col++){
            if(isValid(Board,row,col)){
                Board[row][col]='Q';
                solve(Board,row+1);
                Board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return result;
    }
};