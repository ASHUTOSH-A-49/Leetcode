class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        double ans = 0;
        int i = 0,j = 0;
        int n = prices.size(),m = discounts.size();
        while(i<n && j<m){
            int p = prices[i],d = discounts[j];
            double newp = (double)(p*(100-d))/100;
            ans+=newp;
            i++;j++;
        }
        while(i<n){
            ans+=prices[i];
            i++;
        }
        return ans;
    }
};