class Solution {
public:
int t[2][101][101];
int solve(vector<int> & piles,int p,int i,int M){
    int n = piles.size();
    if(i>=n) return 0;
    if(t[p][i][M]!=-1) return t[p][i][M];
    int res = (p==1)?-1:INT_MAX;
    int stones = 0;
    for(int x = 1;x<=min(2*M,n-i);x++){
        stones+=piles[x+i-1];
        if(p==1){//alice
            res = max(res,stones+solve(piles,0,i+x,max(M,x)));
        }else{
            res = min(res,solve(piles,1,i+x,max(M,x)));
        }
    }

    return t[p][i][M] = res;

}
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        return solve(piles,1,0,1);
    }
};