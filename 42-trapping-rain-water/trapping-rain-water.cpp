class Solution {
public:
    //APPROACH - 2 : using lMax,rMax,l,r,and 2 traversal, SC - O(1)
    int trap(vector<int>& height) {
        int n  = height.size();
        int l = 0,r = n-1,lmax = 0,rmax = 0;
        int ans=  0;
        while(l<=r){
            if(height[l]<lmax) ans+=lmax-height[l];
            if(height[r]<rmax) ans+=rmax-height[r];
            if(height[l] <= height[r]) {
                lmax = max(lmax,height[l]);
                l++;
            }
            else {
                rmax = max(rmax,height[r]);
                r--;
            }
        }
        return ans;
    }
};