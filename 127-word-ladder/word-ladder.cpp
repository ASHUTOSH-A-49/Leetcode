class Solution {
private:
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);
        
        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();
            
            if (word == endWord) return length;
            
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;
                    
                    word[i] = c;
                    
                    if (dict.find(word) != dict.end()) {
                        q.push({word, length + 1});
                        dict.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
        
        return 0;
    }
};