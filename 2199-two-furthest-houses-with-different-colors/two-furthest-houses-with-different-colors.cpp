class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxdist = 0;
        int n = colors.size();
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(colors[i]==colors[j]) continue;
                else maxdist = max(maxdist,j-i);
            }
        }
        return maxdist;
    }
};