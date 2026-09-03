class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long smalelem=1e10;
        int cnto=0,cnte=0;
        for(int i:nums1){
            long long int1=i;
            smalelem= min(int1,smalelem);
            (i&1)? cnto++:cnte++;
            
        }
        if(cnte==0) return true;
        if(cnto==0) return true;
        return (smalelem&1)? true: false;
    }
};