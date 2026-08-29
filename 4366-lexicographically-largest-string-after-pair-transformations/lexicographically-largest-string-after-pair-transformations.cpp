class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<int> pow2(26);
        int k = 1;
        for(int i = 0;i<26;i++){
            pow2[i] = k;
            k*=2;
        }
        vector<string> ans;
        for(int num:nums){
            int i = num;
            string str = "";
            for(int j = 25;j>=0;j--){
                while(i>=pow2[j]){
                    int cnt = i/pow2[j];
                    i%=pow2[j];
                    str.append(cnt,'a'+j);
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};