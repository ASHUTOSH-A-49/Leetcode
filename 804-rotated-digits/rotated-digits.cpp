class Solution {
public:
int getmirror(int n){
    int a = n;
    int b = 0;
    int digs = 0;
    while(n>0){
        digs++;
        n = n/10;
    }
    int c = a;
    for(int i = digs-1;i>=0;i--){
        int mir = c/pow(10,i);
        c = c % (int)pow(10, i);
        if(mir == 1 || mir==0 || mir == 8){
            b = b*10 + mir;
        }else if(mir==2){
            b = b*10 + 5;
        }
        else if(mir==5){
            b = b*10 + 2;
        }else if(mir==6){
            b = b*10 + 9;
        }else if(mir==9){
            b = b*10 + 6;
        }
        else{
            return 0;
        }

    }
    if(a==b) return 0;
    cout<<a<<" "<<b<<endl;
    return 1;
}
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            cnt+=getmirror(i);
        }
        return cnt;
    }
};