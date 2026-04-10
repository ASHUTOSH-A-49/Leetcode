class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<int> hash(101,0);
        vector<vector<int>> indices(101);
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
            indices[nums[i]].push_back(i);
        }
        set<int> distances;
        for(int i = 0;i<101;i++){
            if(hash[i]>=3){
                int j = 2;
                while(j<indices[i].size()){
                    int dist = abs(indices[i][j-2] - indices[i][j-1]) + abs(indices[i][j-1] - indices[i][j]) + abs(indices[i][j] - indices[i][j-2]);
                    distances.insert(dist);
                    j++;
                }
            }
        }
        if(distances.size()>0){
            for(int i:distances){
                return i;
            }
        }
        return -1;
    }
};