class Solution {
public:
bool solve(bool turn,int p1,int p2,int l,int r,vector<int> & nums){
    if(l>r) {
        return (p1>=p2);
    }
    if(turn){
        //only one then enough for p1
        return solve(0,p1+nums[r],p2,l,r-1,nums) ||
               solve(0,p1+nums[l],p2,l+1,r,nums);
    }
    //p1 should win both
    return solve(1,p1,p2+nums[r],l,r-1,nums) &&
           solve(1,p1,p2+nums[l],l+1,r,nums);
}
    bool predictTheWinner(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        return solve(1,0,0,l,r,nums);
    }
};