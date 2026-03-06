class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool check1 = false;
        int cnt1 = 0;
        int cntseg = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
                check1 = true;
            } 
            else{
                if(cnt1>0) cntseg++;
                cnt1 = 0;
                check1 = false;
            } 

        }
        if(cnt1>0) cntseg++;
        cout<<cntseg<<endl;
        if(cntseg==1) return true;
        return false;
    }
};