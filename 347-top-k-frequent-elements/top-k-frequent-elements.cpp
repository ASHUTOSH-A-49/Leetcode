struct CompareSecondMax {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hash;
        for(int i :nums) hash[i]++;
        priority_queue<pair<int,int>,vector<pair<int, int>>, CompareSecondMax> pq;
        for(auto p:hash){
            pq.push(p);
        }
        vector<int> ans;
        while(k>0){
            auto p = pq.top();
            ans.push_back(p.first);
            pq.pop();k--;
        }
        return ans;
    }
};