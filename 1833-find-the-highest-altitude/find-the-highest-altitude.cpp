class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alts;
        alts.push_back(0);
        for(int i:gain){
            int j = alts.size()-1;
            alts.push_back(alts[j]+i);
        }
        int maxalt = 0;
        for(int i:alts){
            maxalt = max(i,maxalt);
        }
        return maxalt;
    }
};