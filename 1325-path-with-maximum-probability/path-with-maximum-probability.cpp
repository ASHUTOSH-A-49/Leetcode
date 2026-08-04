class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int src=start_node,dst=end_node;
        vector<vector<pair<int,double>>> G(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double p=log(succProb[i]);
            G[u].push_back({v,p});
            G[v].push_back({u,p});
        }
        vector<double> dist(n,-1e9);
        priority_queue<pair<double,int>> q;
        dist[src]=0;
        q.push({0,src});
        while(!q.empty()){
            auto[p,node]=q.top();
            q.pop();
            for(auto[i,p2]:G[node]){
                if(p+p2>dist[i]){
                    dist[i]=p+p2;
                    q.push({dist[i],i});
                }
            }
        }
        return (dist[dst]==-1e9)?0:exp(dist[dst]);
    }
};