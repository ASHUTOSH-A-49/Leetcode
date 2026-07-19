class Solution {
public:
    bool DFSconnect(vector<vector<char>> & board,int i,int j,vector<vector<int>> &visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return true;
        if(visited[i][j] || board[i][j]=='X') return false;
        visited[i][j] = 1;
        bool down = DFSconnect(board,i+1,j,visited);
        bool up = DFSconnect(board,i-1,j,visited);
        bool right = DFSconnect(board,i,j+1,visited);
        bool left = DFSconnect(board,i,j-1,visited);
        return down || up || right || left;
    }
    void solve(vector<vector<char>>& board) {
        //approach -  First, we find everything connected to the border and mark it in visited. Then, we loop through the whole board once to flip any unvisited 'O' into 'X'.
        //Because we mark safe border-connected 'O's in the visited array immediately, we no longer need to roll back changes using a stack and queue.
        if(board.empty() || board[0].empty()) return;
        int m = board.size(),n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                //dfs from borders only( faster)
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O' && !visited[i][j]){
                    DFSconnect(board,i,j,visited);
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};