class Solution {
public:
 int matchlet(string s1,string s2){
    int notmatch = 0;
    int n = s1.size();
    for(int i = 0;i<n;i++){
        if(s1[i]!=s2[i]) notmatch++;
    }
    return notmatch;
 }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int m = queries.size();
        int n = dictionary.size();
        vector<string> ans;
        for(int i = 0;i<m;i++){
            string s1 = queries[i];
            int minlet = s1.size();
            for(int j = 0;j<n;j++){
                string s2 = dictionary[j];
                minlet = min(minlet,matchlet(s1,s2));
            }
            if(minlet<=2) ans.push_back(queries[i]);
        }
        return ans;
    }
};