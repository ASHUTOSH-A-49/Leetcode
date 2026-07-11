class Solution {
public:
    //APPROACH - 1 : using PREMAX AND SUFFMAX
    int trap(vector<int>& height) {
        int n  = height.size();
        vector<int> preMax(n),SuffMax(n);
        preMax[0] = height[0];
        SuffMax[n-1] = height[n-1];
        for(int i = 1;i<n;i++){
            preMax[i] = max(preMax[i-1],height[i]);
        }
        for(int i = n-2;i>=0;i--){
            SuffMax[i] = max(SuffMax[i+1],height[i]);
        }
        int ans=  0;
        for(int i = 0;i<n;i++){
            int num = height[i];
            if(num<preMax[i] && num<SuffMax[i]) ans+=min(preMax[i],SuffMax[i])-num;
        }
        return ans;
    }
};