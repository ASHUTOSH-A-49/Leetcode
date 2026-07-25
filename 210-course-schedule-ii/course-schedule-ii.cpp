class Solution {
public:
// approach 2 - BFS using TOPO SORT KAHN's ALGO 

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //CONCEPT - 1. is  topo size using kahn's == n (vertices) then DAG else cycle 
        int V = numCourses;
        vector<vector<int>> G(V);
        for(auto v:prerequisites){
            G[v[0]].push_back(v[1]);
        }
        vector<int> Indeg(V,0);
        for(auto v: G){
            for(int i:v) Indeg[i]++;
        }
        
        queue<int> q;
        
        for(int i = 0;i<V;i++){
            if(Indeg[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int i:G[node]){
                Indeg[i]--;
                if(Indeg[i]==0) q.push(i);
            }
        }
        
        // topo keeps least dependent at last ... acc to ques we need it at first so just reverse the topo obtained
        vector<int> ans;
        reverse(topo.begin(),topo.end());
        return (topo.size()==V) ? topo : ans; 
    }
};