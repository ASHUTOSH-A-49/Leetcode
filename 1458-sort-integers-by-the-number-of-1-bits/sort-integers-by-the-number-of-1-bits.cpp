class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> counts;
        for(int i = 0;i<arr.size();i++){
            int cnt = __builtin_popcount(arr[i]);
            counts.push_back({cnt,arr[i]});
        }
        sort(counts.begin(),counts.end());
        vector<int> ans;
        for(pair p:counts){
            ans.push_back(p.second);

        }
        return ans;
    }
};