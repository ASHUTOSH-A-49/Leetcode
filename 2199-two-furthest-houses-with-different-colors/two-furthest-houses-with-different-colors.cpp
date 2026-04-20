class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxdist = 0;
        int n = colors.size();
        int l = 0,r = n-1;
        while(l<r){
            if(colors[l]==colors[r]){
                r--;
            }else{
                maxdist = max(maxdist,r-l);
                break;
            }
        }
        l = 0,r = n-1;
        while(l<r){
            if(colors[l]==colors[r]){
                l++;
            }else{
                maxdist = max(maxdist,r-l);
                break;
            }
        }
        return maxdist;
    }
};