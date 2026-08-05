class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        vector<vector<int>> G(n);
        
        for(const auto& i : invocations){
            int u = i[0], v = i[1];
            G[u].push_back(v);
        }
        vector<bool> isSusp(n, false);
        isSusp[k] = true;
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i : G[node]){
                if(isSusp[i]) continue;
                q.push(i);
                isSusp[i] = true;
            }
        }
        
        vector<int> visited(n, 0);
        bool check = false;
        for(int i = 0; i < n; i++){
            if(isSusp[i]) continue;
            if(visited[i]) continue;
            visited[i] = 1;
            
            for(int u : G[i]){
                if(isSusp[u]) {
                    check = true;
                    break;
                }
            }
            if(check) break;
        }
        
        if(check){
            for(int i = 0; i < n; i++) ans.push_back(i);
        } else {
            for(int i = 0; i < n; i++){
                if(!isSusp[i]) ans.push_back(i);
            }
        }
        return ans;
    }
};