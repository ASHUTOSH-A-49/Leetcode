class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int ans = -1;
        // map<int,int> freq;
        // set<pair<int,int>> freqidx;
        // int cnt = 1;
        // int i = 0;
        // for(;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]) cnt++;
        //     else {
        //         pair<int,int> p= {i,cnt};
        //         freqidx.insert(p);
        //         freq[cnt]++;
        //         cnt = 1;
        //     }
        // }
        // pair<int,int> p= {i,cnt};
        // freqidx.insert(p);
        // freq[cnt]++;
        // cnt = 1;
        // for( auto p:freqidx){
        //     if(freq[p.second]==1){
        //         ans = nums[p.first];
        //         break;
        //     }
        // }

        unordered_map<int,int> freq;
        unordered_map<int,int> freqCnt;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto p:freq){
            freqCnt[p.second]++;
        }
        for(int n:nums){
            int cnt = freq[n];
            if(freqCnt[cnt]==1) return n;
        }
        return ans;
    }
};