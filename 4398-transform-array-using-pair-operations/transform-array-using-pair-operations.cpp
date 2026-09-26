class Solution {
public:
    bool canTransform(vector<int>& s, vector<int>& t) {
        set<int> tdiff;
        long long sums = 0,sumt = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            tdiff.insert(s[i]-t[i]);
            sums+=s[i];
            sumt+=t[i];
        }
        return sums==sumt;

        for(int i = 0;i<n;i++){
            if(s[i]==t[i]) continue;
            if(tdiff.find(t[i]-s[i])==tdiff.end()) return false;
        }
        return true;
    }
};