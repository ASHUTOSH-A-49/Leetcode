class Solution {
private:
     int BFS(string src,string dest,map<string,vector<string>>& G){
        int V = G.size();
        map<string,int> dist;
        for(auto p:G){
            dist[p.first] = INT_MAX;
        }
        dist[src] = 0;
        queue<pair<string,int>> q;
        q.push({src,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string root = p.first;
            int d = p.second;
            if(G.find(root)==G.end()) continue;
            for(auto node:G[root]){
                if(1+d < dist[node]){
                    dist[node] = 1+d;
                    q.push({node,1+d});
                }
            }
        }
        return (dist.find(dest)!=dist.end()) ? dist[dest] : INT_MAX;
     }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool check = false;
        for(auto w:wordList){
            if(w==endWord){
                check = true;
                break;
            }
        }
        int V = wordList.size();
        if(!check) return 0;
        map<string,vector<string>> G;
        for(int i = 0;i<V-1;i++){
            string u = wordList[i];
            for(int j = i+1;j<V;j++){
                string v = wordList[j];
                int diff = 0;
                for(int k = 0;k<v.size();k++){
                    if(u[k]!=v[k]) diff++;
                }
                if(diff==1){
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            }
        }
        vector<string> sources;
        for(auto w:wordList){
            int diff = 0;
            for(int k = 0;k<w.size();k++){
                if(w[k]!=beginWord[k]) diff++;
            }
            if(diff==1) sources.push_back(w);
        }
        int minladd = min(BFS(beginWord,endWord,G),INT_MAX);
        bool found = false;
        if(minladd!=INT_MAX){
            found = true;
        }
        if(!found){
            for(string s:sources){
                minladd = min(BFS(s,endWord,G),minladd);
            }
            if(minladd!=INT_MAX){
                minladd++;
            }
        }
        cout<<minladd<<endl;
        return (minladd==INT_MAX) ? 0 : minladd+1 ;
    }
};