class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dist;
        int m = nums1.size(),n = nums2.size();
        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<n;j++){
        //         if(i>j || nums1[i]>nums2[j]) continue;
        //         else{
        //             dist.push_back(j-i);
        //         }
        //     }
        // }
        // int maxi = 0;
        // for(int i:dist){
        //     cout<<i<<" ";
        // }
        // for(int i: dist){
        //     maxi = max(maxi,i);
        // }

        int maxi = 0;
        int i = 0;int j = 0;
        while(i<=j && i<m && j<n){
            if(nums1[i]<=nums2[j]){
                maxi = max(j-i,maxi);
                j++;
            }else{
                i++;
                while(i>j) j++;
            }
        }
        return maxi;
    }
};