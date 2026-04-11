class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<pair<int,int>> arr;
        for(int i = 0;i<nums.size();i++){
            pair<int,int> p = {nums[i],i};
            arr.push_back(p);
        }
        int mindist = INT_MAX;
        bool check = false;
        sort(arr.begin(),arr.end());
        for(int i = 2;i<arr.size();i++){
            if(arr[i].first==arr[i-2].first){
                int dist = abs(arr[i].second-arr[i-1].second) + abs(arr[i].second-arr[i-2].second) + abs(arr[i-1].second-arr[i-2].second);
                check  = true;
                mindist = min(mindist,dist);
            }
        }
        if(check) return mindist;
        return -1;
    }
};