class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bool check = false;
        for(auto w:bank){
            if(w==endGene){
                check = true;
                break;
            }
        }
        if(!check) return -1;
        
        unordered_map<string,int> dist;
        for(auto w:bank){
            dist[w] = INT_MAX;
        }
        
        queue<pair<string,int>> q;
        
        int diff = 0;
        for(int k = 0;k<startGene.size();k++){
            if(startGene[k]!=endGene[k]) diff++;
        }
        if(diff==1) return 1;

        for(auto w:bank){
            int d = 0;
            for(int k = 0;k<w.size();k++){
                if(w[k]!=startGene[k]) d++;
            }
            if(d==1){
                dist[w] = 1;
                q.push({w,1});
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string root = p.first;
            int d = p.second;
            cout<<root<<endl;
            if(root==endGene) return d;
            
            string temp = root;
            for(int i = 0;i<temp.size();i++){
                char original = temp[i];
                //all combination of letters from a-z to create the word in list
                for(char c = 'A';c<='Z';c++){
                    if(c==original) continue;
                    temp[i] = c;
                    if(dist.find(temp)!=dist.end() && 1+d < dist[temp]){
                        dist[temp] = 1+d;
                        q.push({temp,1+d});
                    }
                }
                temp[i] = original;
            }
        }
        return -1;
    }
};