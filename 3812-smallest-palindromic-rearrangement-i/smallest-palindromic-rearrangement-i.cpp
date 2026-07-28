class Solution {
public:
    string smallestPalindrome(string s) {
        int n= s.size();
        vector<int> mp(26, 0);
        for(char c:s){
            mp[c-'a']++;
        }
        string s2(n,'0');
        int idx= 0;
        for(int i=0;i<26;i++){
            char c= 'a'+i; int freq= mp[i];
            int cnt= freq/2+idx;
            for(;idx<cnt;idx++){
                s2[n-idx-1]=c;
                s2[idx]=c;
            }
            (freq&1)? mp[c-'a']=1:mp[c-'a']=0;
        }
        for(int i=0;i<26;i++){
            int freq= mp[i];
            if(freq>0) s2[idx]='a'+i;
        }
        return s2;
    }
};