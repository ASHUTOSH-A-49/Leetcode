using ll = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll ans = 0;
        ll ans1 = 0,ans2 = 0,ans3 = 0;
        ans1 = (ll) need1 * cost1 + (ll)need2*cost2;
        ans3 = (ll) costBoth * max(need1,need2);
            if(need1<=need2){
                need2-=need1;
                ans2+=(ll)costBoth * need1;
                need1 = 0;
                ans2+=(ll) need2 * cost2;
            }else{
                
                need1-=need2;
                ans2+=(ll) costBoth * need2;
                need2 = 0;
                ans2+=(ll) need1* cost1;

            }
            cout<<ans1<<" "<<ans2<<endl;
            ans = min({ans1,ans2,ans3});
            return ans;
    }
};