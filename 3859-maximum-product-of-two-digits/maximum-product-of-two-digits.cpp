class Solution {
public:
    vector<int> getDigs(int n){
        vector<int> digs;

        while(n>0){
            digs.push_back(n%10);
            n/=10;
        }
        return digs;
    }
    int maxProduct(int n) {
        vector<int> dig = getDigs(n);
        int maxprod = 0;
        int siz = dig.size();
        for(int i= 0;i<siz;i++){
            for(int j = i+1;j<siz;j++){
                maxprod = max(maxprod,dig[i]*dig[j]);
            }
        }
        return maxprod;
    }
};