class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int,vector<int>> mp; //freq,last pos, interv
        for(int i = 0;i<nums.size();i++){
            int n = nums[i];
            if(mp.count(n)){
                vector<int> &v = mp[n];
                if(v[0]==-1) continue;
                v[0]++;
                int interv = v[2],last = v[1];
                if(interv==0) {
                    interv = i-last;
                    v[2] = interv;
                    v[1] = i;
                }else{
                    if(i-last != interv) v[0] = -1;
                    else v[1] = i;
                }
                
                
            }else{
               mp[n] = {1,i,0}; 
            }
            
        }
        for(auto & [num,v]:mp){
            if(v[0]>=3) cnt++;
        }
        return cnt;
    }
};