class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = INT_MAX;
        string test = "balloon";
        map<char,int> hasht;
        for(char c:test){
            hasht[c]++;
        }
        map<char,int> hash;
        for(char c:text){
            hash[c]++;
        }
        for(auto p:hasht){
            char c = p.first;int fac = p.second;
            ans = min(ans,hash[c]/fac);
        
        }
        return ans;
    }
};