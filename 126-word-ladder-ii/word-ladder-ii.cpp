class Solution {
private:
    void ladderLength(string beginWord, string endWord, vector<string>& wordList,unordered_map<string, int>& dist) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        dict.erase(beginWord);
        unordered_set<string> visited_lev;
        while (!q.empty()) {
            int level_size = q.size();
            for(int j=0;j<level_size;j++){
                string word = q.front();
                q.pop();
                if (word == endWord) return;
                int current_dist = dist[word];
                for (int i = 0; i < word.size(); i++) {
                    char originalChar = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        word[i] = c;
                        if (dict.find(word) != dict.end()) {
                            if(dist.find(word) == dist.end()){
                                dist[word] = current_dist+1;
                                q.push(word);
                                visited_lev.insert(word);
                            }
                        }
                    }
                    word[i] = originalChar;
                }
            }
            for(auto w:visited_lev) dict.erase(w);
            visited_lev.clear();
        }
    }

public:
//To completely eliminate dead ends and pass all test cases, we must run the DFS backwards from endWord to beginWord. Since every step backward decreases the distance to beginWord by exactly 1, every single path explored is guaranteed to be a valid shortest path.
    void DFS(string beginWord, string endWord, unordered_set<string> & dict,int &slen,int currlen,vector<string> &path,vector<vector<string>> & ans,unordered_map<string,int> & dist){
        if(beginWord==endWord) {
            vector<string> r=path;
            reverse(r.begin(),r.end());
            ans.push_back(r);
            return;
        }
         string temp = beginWord;
        for(int i = 0; i < temp.size(); i++){
            char original = temp[i];
            //all combination of letters from a-z to create the word in list
            for(char c = 'a'; c <= 'z'; c++){
                if(c==original) continue;
                temp[i] = c;
                if (dist.find(temp) != dist.end() && dist[temp]==currlen-1) {
                    path.push_back(temp);
                    DFS(temp,endWord,dict,slen,currlen-1,path,ans,dist);
                    path.pop_back(); //backtrack
                }
            }
            temp[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> dist;
        ladderLength(beginWord,endWord,wordList,dist);
        if(dist.find(endWord)==dist.end()) return {};
        int len = dist[endWord];
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> path;
        path.push_back(endWord);
        DFS(endWord,beginWord,dict,len,len,path,ans,dist);
        return ans;
    }
};