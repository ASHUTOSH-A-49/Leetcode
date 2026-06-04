class Solution {
public:
int cntwavy(int n){
    if((n/100)==0) return 0;
    int cnt = 0;
    // vector<int> digs;
    int prevdig = n%10;
    n = n/10;
    while(n/10!=0){
        int dig = n%10;
        n/=10;
        int nextdig = n%10;
        if((dig<nextdig && dig<prevdig) || (dig>nextdig && dig>prevdig)) cnt++;
        prevdig = dig;
    }
    // int siz = digs.size();
    // int cnt = 0;
    // for(int i = 1;i<siz-1;i++){
    //     if((digs[i]>digs[i-1] && digs[i]>digs[i+1]) || (digs[i]<digs[i-1] && digs[i]<digs[i+1])) cnt++;
    // }
    return cnt;
}
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1;i<=num2;i++){
            ans+=cntwavy(i);
        }
        return ans;
    }
};