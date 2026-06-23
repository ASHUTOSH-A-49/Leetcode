class Solution {
public:
int MOD = 1e9+7;
//CONSTRUCTIVE APPROACH + DP + PRESUM
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1; //transformed the range as 0-> r-l+1 is similar to l->r only order matters

        vector<vector<int>> up(n+1,vector<int>(m,0)), down(n+1,vector<int>(m,0));
        //up -  last step was incr.... down  -  last step was incr...
        for(int x = 0;x<m;x++){
            for(int y = 0;y<m;y++){
                if(x==y) continue;
                //base cases
                if(x<y) up[2][y] = (up[2][y]+1) % MOD;
                else down[2][y] = (down[2][y]+1) % MOD;
            }
        }

        for(int i = 3;i<=n;i++){
            vector<int> prefUp(m+1,0),prefDown(m+1,0);
            for(int v = 0;v<m;v++){
                prefUp[v+1] = (prefUp[v]+up[i-1][v]) % MOD;
                prefDown[v+1] = (prefDown[v]+down[i-1][v]) % MOD;
            }

            for (int x = 0;x<m;x++){
                up[i][x] = prefDown[x];
                //sum of Down[i-1][x] for x<y
                down[i][x] = ((prefUp[m]-prefUp[x+1])%MOD + MOD)%MOD;
                //sum of Up[i-1][x] for x>y
            }
        }
        long long ans = 0;
        if(n==1){
            ans = m;
            //single elem valid always
        }else{
            for(int i = 0;i<m;i++){
                ans = (ans+up[n][i]+down[n][i])%MOD;
            }
        }
        return ans;
    }
};