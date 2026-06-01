class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int n = cost.size();
        int ans = 0;
        while(n>2){
            ans+=cost[0];
            ans+=cost[1];
            cost.erase(cost.begin(),cost.begin()+3);
            n = cost.size();
        }
        if(n==0) return ans;
        for(int i = 0;i<n;i++){
            ans+=cost[i];
        }
        return ans;
    }
};