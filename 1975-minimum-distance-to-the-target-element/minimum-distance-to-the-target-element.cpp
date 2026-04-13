class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<int> dist;
        for(int i = 0;i<start;i++){
            if(nums[i]==target) dist.push_back(start-i);
        }
        for(int i = start;i<nums.size();i++){
            if(nums[i]==target) dist.push_back(i-start);
        }
        int mindist = 1e5;
        for(int i = 0;i<dist.size();i++){
            mindist = min(mindist,dist[i]);
        }
        return mindist;
    }
};