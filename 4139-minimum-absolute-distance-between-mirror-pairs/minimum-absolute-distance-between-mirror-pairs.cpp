class Solution {
public:
int rev(int x){
    int a = 0;
    while(x>0){
        a=a*10 + x%10;
        x/=10;
    }
    return a;
}
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> hash;
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]].push_back(i);
        }
        int minmirr = 1e9;
        bool check = false;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int target = rev(nums[i]);
            
            if (hash.count(target)) {
                const vector<int>& indices = hash[target];
                auto it = upper_bound(indices.begin(), indices.end(), i);
                
                if (it != indices.end()) {
                    minmirr = min(minmirr, *it - i);
                    check = true;
                }
            }
        }
        // for(auto p : hash){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        if(check) return minmirr;
        return -1;
    }
};