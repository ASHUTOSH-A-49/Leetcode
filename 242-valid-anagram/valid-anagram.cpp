class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashs(256,0);
        vector<int> hasht(256,0);
        for(int i = 0;i<s.size();i++){
            hashs[s[i]]++;
            
        }
        for(int i = 0;i<t.size();i++){
            hasht[t[i]]++;
        }
        bool check = true;
        for(int i = 0;i<256;i++){
            if(hashs[i]!=hasht[i]) {
                check = false;
                break;
            }
        }
        return check;
    }
};