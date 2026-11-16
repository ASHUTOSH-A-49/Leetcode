class Solution {
public:
    void add(vector<int> & v1,int sum){
        if(sum==0){
            v1.push_back(sum);
            return;
        }
        vector<int> temp;
        while(sum>0){
            int d = sum%10;
            temp.push_back(d);
            sum/=10;
        }
        reverse(temp.begin(),temp.end());
        for(int i:temp){
            v1.push_back(i);
        }
    }
    string digitSum(string s, int k) {
        vector<int> v;
        for(char c:s){
            v.push_back(c-'0');
        }
        while(v.size()>k){
            vector<int> v1;
            int sum = 0;
            int i = 0;
            for(;i<v.size();i++){
                sum+=v[i];
                if(((i+1)%k) == 0 ){
                    add(v1,sum);
                    sum = 0;
                }
            }
            if((i%k)!=0){
                add(v1,sum);
            }
            v = v1;
        }
        string ans="";
        for(int i:v){
            ans+= to_string(i);
        }
        return ans;
        
    }
};