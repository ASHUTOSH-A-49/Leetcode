class Solution {
public:
// approach 1 - DFS TOPO SORT + cycle detection
bool DFScycle(vector<vector<int>> & G,vector<int> & visited,vector<int> &pathvis,int node){
      visited[node] = 1;
      pathvis[node] = 1;
      for(int i : G[node]){
          if(!visited[i]){
              if(DFScycle(G,visited,pathvis,i)) return true;
              
          }else if(pathvis[i]){
              //seen this twice in current path
              return true;
          }
      }
      pathvis[node] = 0; //backtrack
      
      return false;
  }
  void DFSTopo(vector<vector<int>> & G, vector<int> & vis,stack<int> &st,int strt){
      if(vis[strt]) return;
      vis[strt] = 1;
      for(int i:G[strt]){
          DFSTopo(G,vis,st,i);
      }
      st.push(strt);
  }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //CONCEPT - 1. check cycle 
        //        - 2. if no cycle - give the TOPO SORT
        vector<int> topo;
        int V = numCourses;
        vector<vector<int>> G(V);
        for(auto v:prerequisites){
            G[v[0]].push_back(v[1]);
        }
        vector<int> visited(V,0);
        vector<int> pathvis(V,0);
    
        bool checkCycle = false;

        for(int i = 0;i<V;i++){
            if(DFScycle(G,visited,pathvis,i)) {
                checkCycle = true;
                break;
            }
        }
        if(checkCycle) return topo;
        stack<int> st;
        vector<int> vis(V,0);
        for(int i = 0;i<V;i++){
            DFSTopo(G,vis,st,i);
        }
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        // topo keeps least dependent at last ... acc to ques we need it at first so just reverse the topo obtained
        reverse(topo.begin(),topo.end());
        return topo;
    }
};