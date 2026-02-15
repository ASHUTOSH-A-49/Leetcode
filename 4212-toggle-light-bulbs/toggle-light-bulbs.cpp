class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> modearr(101,0);
        for(int i = 0;i<bulbs.size();i++){
            if(modearr[bulbs[i]]==0)modearr[bulbs[i]] = 1;
            else modearr[bulbs[i]]=0;
        }
        vector<int> ans;
        for(int i = 0;i<101;i++){
            if(modearr[i]==1) ans.push_back(i);
        }
        return ans;
    }
};