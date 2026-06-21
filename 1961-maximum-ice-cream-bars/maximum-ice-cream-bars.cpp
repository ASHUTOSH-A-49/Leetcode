class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i = 0;
        while(coins>0 && i<costs.size()){
            if(costs[i]<=coins){
                coins-=costs[i];
                i++;
            }else break;
        }
        return i;
    }
};