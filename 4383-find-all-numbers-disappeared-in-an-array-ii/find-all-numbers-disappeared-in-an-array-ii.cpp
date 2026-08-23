class Solution {
public:
    bool BSFind(vector<int> &nums, int n){
        int low = 0,high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==n) return true;
            if(nums[mid]>n) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int st = -1,ed = -1;
        for(int i = lower;i<=upper;i++){
            if(!BSFind(nums,i)){
                if(st==-1) st = i;
                ed = i;
            }else{
                if(st!=-1 && ed!=-1){
                    ans.push_back({st,ed});
                    st = -1;ed = -1;   
                }
                
            }
        }
        if(st!=-1 && ed!=-1){
                    ans.push_back({st,ed});
                    st = -1;ed = -1;   
        }
        return ans;
    }
};