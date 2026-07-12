class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int siz = flowerbed.size();
        for(int i = 0;i<siz;i++){
            if(flowerbed[i]==1 || (i>0 && flowerbed[i-1]==1) || (i<siz-1&& flowerbed[i+1]==1)){
                continue;
            }
            else {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        cout<<cnt<<endl;
        return cnt>=n;

    }
};