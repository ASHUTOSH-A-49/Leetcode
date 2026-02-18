class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            if(strs[i] == "_") continue; 
            string s = strs[i];
            vector<string> anags;
            vector<int> hash1(26, 0); 
            for(char c : s) hash1[c - 'a']++;
            for(int j = i; j < n; j++) {
                if(strs[j] != "_" && strs[j].size() == s.size()) {
                    vector<int> hash2(26, 0);
                    for(char c : strs[j]) hash2[c - 'a']++;
                    
                    bool isAnagram = true;
                    for(int k = 0; k < 26; k++) {
                        if(hash1[k] != hash2[k]) {
                            isAnagram = false;
                            break;
                        }
                    }
                    
                    if(isAnagram) {
                        anags.push_back(strs[j]);
                        strs[j] = "_";
                    }
                }
            }
            ans.push_back(anags);
        }
        return ans;
    }
};