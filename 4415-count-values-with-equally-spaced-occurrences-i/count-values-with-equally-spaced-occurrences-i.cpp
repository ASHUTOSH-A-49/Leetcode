class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt = 0;
        vector<int> n1;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto [i,f]:mp){
            if(f==3) n1.push_back(i);
        }
        for(int i:n1){
            int interv = 0,freq = 0,seen = -1;
            for(int j = 0;j<nums.size();j++){
                if(nums[j]==i){
                    if(freq==0){
                        freq++;
                        seen = j;
                    }else if(freq==1){
                        freq++;
                        interv = j-seen;
                        seen = j;
                    }else{
                        if(j-seen==interv) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};