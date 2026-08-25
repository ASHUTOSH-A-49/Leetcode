class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        sort(coins.begin(),coins.end());
        vector<int> C(amount+1,INT_MAX);
        C[0] = 0;
        for(int i = 1;i<=amount;i++){
            int res = INT_MAX;
            for(int c:coins){
                if(c>i) break;
                // cout<<"enter "<<i<<endl;
                res = min(res,C[i-c]);
            }

            if(res!=INT_MAX) C[i] = 1+res;
            
        }
        // for(int i:C) cout<<i<<" ";

        return (C[amount]==INT_MAX) ? -1: C[amount];

    }
};