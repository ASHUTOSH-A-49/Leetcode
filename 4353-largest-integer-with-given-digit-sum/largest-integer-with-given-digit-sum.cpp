class Solution {
public:
pair<int,int> Dig(int n){
    int sum = 0,dig = 0;
    while(n){
        sum+=n%10;
        dig++;
        n/=10;
    }
    return{dig,sum};
}
    int largestInteger(int n, int s) {
        if(s>9*n) return -1;
        if(s==0) return 0;
        int i = 9;
        int ans = 0;
        vector<int> ansarr(n,0);
        int idx = 0;
        int sum = 0;
        while(i>=0 && idx<n){
            if(sum+i>s){
                i--;
            }else{
                sum+=i;
                ansarr[idx] = i;
                idx++;
            }
        }
        for(int k:ansarr){
            ans = ans*10 + k;
        }
        for(int m:ansarr) cout<<m<<" ";
        return ans;
    }
};