class Solution {
public:
bool simulate(int first,unordered_map<int,int> modfreq,int n){
    if(modfreq[first]==0) return false;
    modfreq[first]--;
    int turn = false;//bob
        int summod = first;
        for(int i = 1;i<n;i++){
            int mod = summod%3;
            // cout<<mod<<endl;
            if(mod==1){
                if(modfreq[0]>0 || modfreq[1]>0){
                    
                    if (modfreq[0]>0){
                        modfreq[0]--;
                        summod = mod+0;
                    }else{
                        if(modfreq[1]>0){
                            modfreq[1]--;
                            summod = mod+1;
                        }
                        
                    }
                }else{
                    return !turn;
                }
            }else if(mod==2){
                // cout<<"enter 2"<<endl;
                // for(auto p:modfreq){
                //     cout<<p.first<<" "<<p.second<<endl;
                // }
                if(modfreq[0]>0 || modfreq[2]>0){
                    // cout<<"enter 2 if"<<endl;
                    if (modfreq[0]>0){
                        modfreq[0]--;
                        summod = mod+0;
                    }else{
                        if(modfreq[2]>0){
                            modfreq[2]--;
                            summod = mod+2;
                        } 
                    }
                }else{
                    // cout<<"enter 2 else"<<endl;
                    return !turn;
                    
                }
            }
            turn  = !turn;
        }
        return false;
}
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int> modfreq;
        for(int i:stones){
            int mod = i%3;
            modfreq[mod]++;
        }
        
        return simulate(1,modfreq,n) || simulate(2,modfreq,n);
    }
};