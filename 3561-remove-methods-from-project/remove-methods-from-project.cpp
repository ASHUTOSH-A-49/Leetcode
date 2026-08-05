class Solution {
public:
    int BFS(vector<vector<int>> & G,vector<int> & visited,vector<bool> & isSusp,int root){
        if(visited[root]) return 0;
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(int i:G[node]){
                if(visited[i]) continue;
                if(isSusp[i]) return 1;
                q.push(i);
                visited[i] = 1;
            }
        }
        return 0;
        
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        vector<vector<int>> G(n);
        for(auto i:invocations){
            int u = i[0],v = i[1];
            G[u].push_back(v);
        }
        vector<bool> isSusp(n,false);
        isSusp[k] = true;
        //BFS from suspicious to get al suspicious
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i:G[node]){
                if(isSusp[i]) continue;
                q.push(i);
                isSusp[i] = true;
            }
        }
        // for(bool b:isSusp) cout<<b<<" ";
        // bool check = false;
        vector<int> visited(n,0);
        bool check  = false;
        for(int i = 0;i<n;i++){
            if(isSusp[i]) continue;
            if(BFS(G,visited,isSusp,i)) {
                check = true;
                break;
            }
        }
        if(check){
            for(int i = 0;i<n;i++) ans.push_back(i);
        }else{
            for(int i = 0;i<n;i++){
                if(!isSusp[i]) ans.push_back(i);
            }
        }

        return ans;
    }
};