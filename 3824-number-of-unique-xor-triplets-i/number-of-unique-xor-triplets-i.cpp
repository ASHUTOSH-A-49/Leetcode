class Solution {
public:
int maxP(int n){
    int i = 1;
    while(pow(2,i)<=n){
        i++;
    }
    cout<<i<<endl;
    if(pow(2,i)>n) i--;
    return i;
}
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();
        if(n<=2) return n;
        cout<<maxP(n)<<endl;
        return pow(2,maxP(n)+1);
    }
};