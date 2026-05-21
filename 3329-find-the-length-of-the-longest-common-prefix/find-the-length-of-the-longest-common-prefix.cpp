class Solution {
public:
int highdiv(int a){
        int div = 1;
        while (a / div >= 10) {
            div *= 10;
        }
        return div;
    }
    int getCommonDig(int a,int diva,int b,int divb){
        int c = 0;
        while(diva>0 && divb>0){
            int dig1 = a/diva, dig2 = b/divb;
            if(dig1!=dig2) break;
            c++;
            a%=diva;
            b%=divb;
            diva/=10;divb/=10;
        }
        return c;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        auto compar = [this](int x, int y) {
            long long dx = highdiv(x), dy = highdiv(y);
            long long vx = (long long)x * dy, vy = (long long)y * dx;
            if (vx != vy) return vx < vy;
            return x < y;
        };
        sort(arr1.begin(), arr1.end(), compar);
        sort(arr2.begin(), arr2.end(), compar);
        int cntlong = 0;
        int i = 0, j = 0;
        while(i < arr1.size() && j < arr2.size()){
            int len = getCommonDig(arr1[i],highdiv(arr1[i]),arr2[j],highdiv(arr2[j]));
            cntlong = max(cntlong,len);
            long long dx = highdiv(arr1[i]), dy = highdiv(arr2[j]);
            long long vx = (long long)arr1[i] * dy, vy = (long long)arr2[j] * dx;
            if (vx < vy) {
                i++;
            } else if (vx > vy) {
                j++;
            } else {
                if (arr1[i] < arr2[j]) i++;
                else j++;
            }
        }
        return cntlong;
    }

};