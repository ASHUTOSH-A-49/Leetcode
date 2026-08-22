class Solution {
public:
pair<int,int> getD(int n){
    int dsum = 0;
    int dprod = 1;
    while(n>0){
        int d = n%10;
        n/=10;
        dsum+=d;
        dprod = dprod*d;
    }
    return {dsum,dprod};
}
    bool checkDivisibility(int n) {
        auto [dsum,dprod] = getD(n);
        return (n%(dsum+dprod)==0);
    }
};