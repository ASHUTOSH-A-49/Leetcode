class Solution {
public:
int n;
int score[50001];
    int solve(vector<int>& Val,int idx){
        if(idx>=n){
            return 0;
        }
        if(score[idx]!=-2e9)return score[idx];
        int result=(n-idx>=1)?Val[idx]-solve(Val,idx+1):-1e9;
        if(n-idx>=2){
            result=max(result,Val[idx]+Val[idx+1]-solve(Val,idx+2));
        }
        if(n-idx>=3){
            result=max(result,Val[idx]+Val[idx+1]+Val[idx+2]-solve(Val,idx+3));
        }
        return score[idx]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        // 1 = alice turn, 0 = bob turn 
        for (int i = 0; i < n; ++i) {
            score[i] = -2e9;
        }
        int diff=solve(stoneValue,0);
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else return "Tie";
    }
};