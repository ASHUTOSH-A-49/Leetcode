class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(),m = station.size();
        vector<int> l(n),r(n);
        int j = 0;
        for(int i = 0;i<n;i++){
            while(j<m && station[j]!=skill[i]) j++;
            l[i] = j;
            j++;
        }
        j = m-1;
        for(int i = n-1;i>=0;i--){
            while(j>=0 && station[j]!=skill[i]) j--;
            r[i] = j;
            j--;
        }
        int maxg = 0;
        for(int i =1;i<n;i++){
            maxg = max(maxg,r[i]-l[i-1]);
        }
        return maxg;
    }
};