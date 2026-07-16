class Solution {
public:
void DFS(vector<vector<int>> &mat,vector<int> &visited,int start){
    visited[start] = 1;
    vector<int> v  = mat[start];
    for(int i:v){
        if(visited[i]) continue;
        DFS(mat,visited,i);
    }
    return;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> G(n+1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                if(isConnected[i][j]==1){
                    G[i+1].push_back(j+1);
                }
            }
        }
        vector<int> visited(n+1,0);
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(!visited[i]) {
                cnt++;
                DFS(G,visited,i);
            }
        }
        return cnt;
    }
};