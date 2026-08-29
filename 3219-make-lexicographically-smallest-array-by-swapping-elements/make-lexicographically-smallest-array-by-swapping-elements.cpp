
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n= nums.size();
        vector<pair<int,int>> temp;
        for(int i= 0;i<n;i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end());
        int l = 0;
        while(l<n){
            int r = l+1;
            vector<int> pos = {temp[l].second};
            while(r<n && (temp[r].first-temp[r-1].first)<=limit){
                pos.push_back(temp[r].second);//push idx
                r++;

            }
            sort(pos.begin(),pos.end());
            //once the union ends place values at their respective idx
            for(int i = 0;i<r-l;i++){
                nums[pos[i]] = temp[l+i].first;
            }
            l = r;
        }
        return nums;

    }
};