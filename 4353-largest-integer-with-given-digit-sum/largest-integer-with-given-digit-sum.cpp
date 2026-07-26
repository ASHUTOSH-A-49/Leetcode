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
        int i = 1;
        int ans = -1;
        while(Dig(i).first<=n){
            if(Dig(i).second==s) ans = i;
            i++;
        }
        return ans;
    }
};