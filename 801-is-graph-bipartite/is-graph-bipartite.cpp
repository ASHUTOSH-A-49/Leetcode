class Solution {
public:
bool BFS(vector<vector<int>>&G,vector<int>&vis,vector<int>&col,int start){
    queue<int>q;
    vis[start]=1;
    q.push(start);
    col[start]=1;
    while(!q.empty()){
        int siz=q.size();
        for(int k=0;k<siz;k++){
            int n=q.front();q.pop();
            int currcol=col[n];
            for(int i:G[n]){
                if(vis[i]){
                    if(col[i]==currcol)return false;
                    continue;
                }
                q.push(i);
                col[i]=!currcol;
                vis[i]=1;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
    vector<int>colors(n,0);
    vector<int>vis(n,0);
    for(int i=0;i<n;++i){
        if(!vis[i]){
            if(!BFS(graph,vis,colors,i))return false;
        }
    }
    return true;


    }
};