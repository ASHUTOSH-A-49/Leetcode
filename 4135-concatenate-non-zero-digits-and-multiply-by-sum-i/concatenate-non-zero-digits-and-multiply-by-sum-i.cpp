class Solution {
public:
int revint(int n){
    int ans = 0;
    while(n){
        ans = ans*10 + n%10;
        n/=10;
    }
    return ans;
}
pair<int,int> nonZero(int n){
    int ans = 0,sum = 0;
    while(n){
        int d = n%10;
        if(d!=0){
            ans = ans*10+d;sum+=d;
        }
        n/=10;
    }
    return {ans,sum};
}
    long long sumAndMultiply(int n) {
        auto p = nonZero(revint(n));
        // cout<<p.first<<" "<<p.second;
        return (long long) p.first * p.second ;
    }
};