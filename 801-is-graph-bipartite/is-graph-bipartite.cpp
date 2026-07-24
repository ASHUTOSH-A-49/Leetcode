class Solution {
public:
bool BFS(vector<vector<int>>&G,vector<int>&col,int start){
    queue<int>q;
    q.push(start);
    col[start]=1;
    while(!q.empty()){
        int siz=q.size();
        for(int k=0;k<siz;k++){
            int n=q.front();q.pop();
            int currcol=col[n];
            for(int i:G[n]){
                if(col[i]!=-1){
                    if(col[i]==currcol)return false;
                    continue;
                }
                q.push(i);
                col[i]=!currcol;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
    vector<int>colors(n,-1);
    // vector<int>vis(n,0);
    for(int i=0;i<n;++i){
        if(colors[i]==-1){
            if(!BFS(graph,colors,i))return false;
        }
    }
    return true;


    }
};