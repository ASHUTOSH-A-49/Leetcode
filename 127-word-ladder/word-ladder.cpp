class Solution {
private:
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool check = false;
        for(auto w:wordList){
            if(w==endWord){
                check = true;
                break;
            }
        }
        if(!check) return 0;
        
        unordered_map<string,int> dist;
        for(auto w:wordList){
            dist[w] = INT_MAX;
        }
        
        queue<pair<string,int>> q;
        
        int diff = 0;
        for(int k = 0;k<beginWord.size();k++){
            if(beginWord[k]!=endWord[k]) diff++;
        }
        if(diff==1) return 2;

        for(auto w:wordList){
            int d = 0;
            for(int k = 0;k<w.size();k++){
                if(w[k]!=beginWord[k]) d++;
            }
            if(d==1){
                dist[w] = 2;
                q.push({w,2});
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string root = p.first;
            int d = p.second;
            if(root==endWord) return d;
            
            string temp = root;
            for(int i = 0;i<temp.size();i++){
                char original = temp[i];
                //all combination of letters from a-z to create the word in list
                for(char c = 'a';c<='z';c++){
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
        return 0;
    }
};