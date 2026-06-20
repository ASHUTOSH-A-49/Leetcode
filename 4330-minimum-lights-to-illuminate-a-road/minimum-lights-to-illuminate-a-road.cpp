class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> span(n+1,0);
        for(int i = 0;i<n;i++){
            int v = lights[i];
            if(v>0){
                int minr  = max(0,i-v),maxr = min(n-1,i+v);
                span[minr]++;
                span[maxr+1]--;
            }
        }
        vector<int> illum(n,0);
        int l = 0;
        for(int i = 0;i<n;i++){
            l+=span[i];
            if(l>0) illum[i] = 1;
        }
        vector<int> nonillum;
        for(int i = 0;i<n;i++){
            if(illum[i]==0) nonillum.push_back(i);
        }

        int extras = 0;
        int i = 0;
        int k = nonillum.size();
        while(i<k){
            extras++;
            int miss = nonillum[i];
            while(i<k && nonillum[i] <=miss+2) i++;
        }
        return extras;
    }
};