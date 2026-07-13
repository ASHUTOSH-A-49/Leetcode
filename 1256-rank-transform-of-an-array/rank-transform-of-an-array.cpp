class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr2 = arr;
        sort(arr2.begin(),arr2.end());
        unordered_map<int,int> rank;
        int ranknum = 1;
        for(int i = 0;i<arr2.size();i++){
            if(rank.count(arr2[i])==0){
                rank[arr2[i]] = ranknum++;
            }
        }
        vector<int> ans;
        for(int i = 0;i<arr.size();i++){
            ans.push_back(rank[arr[i]]);
        }
        return ans;
    }
};