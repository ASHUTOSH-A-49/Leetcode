class Solution {
public:
    string smallestPalindrome(string s) {
        int n= s.size();
        map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        string s2(n,'0');
        int idx= 0;
        for(auto p:mp){
            char c= p.first; int freq= p.second;
            int cnt= freq/2+idx;
            for(;idx<cnt;idx++){
                s2[n-idx-1]=c;
                s2[idx]=c;
            }
            (freq&1)? mp[c]=1:mp[c]=0;
        }
        for(auto p:mp){
            int freq= p.second;
            if(freq>0) s2[idx]=p.first;
        }
        return s2;
    }
};