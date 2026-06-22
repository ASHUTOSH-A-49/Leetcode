class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int ans = INT_MAX;
        map<char,int> hasht;
        for(char c:target){
            hasht[c]++;
        }
        map<char,int> hash;
        for(char c:s){
            hash[c]++;
        }
        for(auto p:hasht){
            char c = p.first;int fac = p.second;
            ans = min(ans,hash[c]/fac);
        
        }
        return ans;
    }
};