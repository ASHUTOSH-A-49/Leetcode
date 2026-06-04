class Solution {
public:
int cntwavy(int n){
    if((n/100)==0) return 0;
    vector<int> digs;
    while(n){
        int dig = n%10;
        digs.push_back(dig); 
        n/=10;
    }
    int siz = digs.size();
    int cnt = 0;
    for(int i = 1;i<siz-1;i++){
        if((digs[i]>digs[i-1] && digs[i]>digs[i+1]) || (digs[i]<digs[i-1] && digs[i]<digs[i+1])) cnt++;
    }
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