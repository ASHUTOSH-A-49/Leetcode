class Solution {
public:
void DFS(vector<vector<int>> & graph,vector<int> & path,vector<vector<int>> & ans,int src,int dest){
    if(src==dest) {
        ans.push_back(path);
        return;
    }
    for(int i:graph[src]){
        path.push_back(i);
        DFS(graph,path,ans,i,dest);
        path.pop_back(); //backtrack
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> path;
        path.push_back(0);
        DFS(graph,path,ans,0,n-1);
        return ans;
    }
};