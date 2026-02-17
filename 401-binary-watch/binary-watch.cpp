class Solution {
public:
int check1(int d){
    int cnt1 = 0;
    while(d>0){
        int dig = d%2;
        if(dig==1) cnt1++;
        d/=2;
    }
    return cnt1;
}
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int hr = 0;hr<12;hr++){
            for(int min = 0;min<60;min++){
                if(check1(hr)+check1(min)==turnedOn){
                    ans.push_back(to_string(hr)+ ":" + (min<10?"0":"")+ to_string(min));
                }
            }
        }
        return ans;
        
    }
};