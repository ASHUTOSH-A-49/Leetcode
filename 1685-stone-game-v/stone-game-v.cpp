int dp[501][501];
class Solution {
public:
int solve(int l,int r,vector<int> & presum, vector<int> & stoneValue){
    if(l>=r){
        return 0;
    }
    if(dp[l][r]!=-1) return dp[l][r];
    int sum = 0;
    for(int p=l;p<r;p++){
            int lsum=(l==0)?presum[p]:presum[p]-presum[l-1];
            int rsum=presum[r]-presum[p];
            if(lsum>rsum){
                sum=max(sum,rsum+solve(p+1,r,presum,stoneValue));
            }else if(lsum<rsum){
                sum=max(sum,lsum+solve(l,p,presum,stoneValue));
            }else{
                int takel=lsum+solve(l,p,presum,stoneValue);
                int taker=rsum+solve(p+1,r,presum,stoneValue);
                sum=max(sum,max(takel,taker));
            }
        }
    return dp[l][r] = sum;
}
    int stoneGameV(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        if(n<=1) return 0;
        memset(dp,-1,sizeof(dp));
        vector<int> presum(n);
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=stoneValue[i];
            presum[i] = sum;
        }
        return solve(0,n-1,presum,stoneValue);
    }
};