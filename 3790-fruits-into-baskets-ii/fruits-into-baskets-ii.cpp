class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> vis(n,0);
        int cntplaced = 0;
        for(int f:fruits){
            for(int i = 0;i<n;i++){
                int b = baskets[i];
                if(!vis[i] && b>=f){
                    vis[i] = 1;
                    cntplaced++;
                    break;
                }
            }
        }
        return n-cntplaced;
    }
};