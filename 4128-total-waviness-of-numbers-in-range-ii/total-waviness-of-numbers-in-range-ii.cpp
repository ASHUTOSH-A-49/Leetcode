class Solution {
public:
typedef long long ll;
ll dpN[16][10][10];
ll dpW[16][10][10];
string s;
int n;
    pair<ll,ll> solve(int curr,int prev1,int prev2,bool isLimitedWithActualNumber,bool isLeadingZero){
        if(curr==n) return {1,0} ;//no more score can be gen and we found one last no.

        if(!isLimitedWithActualNumber && !isLeadingZero && prev2>=0 && prev1>=0){
            //if both false then only memoize 
            if(dpN[curr][prev1][prev2]!=-1 && dpW[curr][prev1][prev2]!=-1){
                return {dpN[curr][prev1][prev2],dpW[curr][prev1][prev2]};
            }
        }

        ll totalNumbers = 0;
        ll totalWavySc = 0;

        int limitDig = (isLimitedWithActualNumber) ? s[curr]-'0' : 9;
        for(int digit = 0;digit<=limitDig;digit++){
            bool isNewLeadingZero = isLeadingZero && (digit==0) ;
            int newPrev2 = prev1;
            int newPrev1 = isNewLeadingZero?-1: digit;

            auto [remainTotalNo,remainTotalWavesc] = solve(curr+1,newPrev1,newPrev2,isLimitedWithActualNumber && (digit==limitDig),isNewLeadingZero);

            if(!isNewLeadingZero && prev2>=0 && prev1>=0){
                bool isPeak = (prev2>prev1 && digit>prev1);
                bool isValley = (prev2<prev1 && digit<prev1);
                if(isPeak || isValley) totalWavySc+=remainTotalNo;
            }
            totalNumbers +=remainTotalNo;
            totalWavySc +=remainTotalWavesc;
        }
        
if(!isLimitedWithActualNumber && !isLeadingZero && prev2>=0 && prev1>=0){
            //if both false then only memoize 
                dpN[curr][prev1][prev2] = totalNumbers;
                dpW[curr][prev1][prev2] = totalWavySc;
        }
        return {totalNumbers,totalWavySc};
    }
    ll func (ll num){
        memset(dpN, -1, sizeof(dpN));
        memset(dpW, -1, sizeof(dpW));
        if(num<100) return 0; // we need atleast 3 dig for peak / valley
        s = to_string(num);
        n = s.length();
        auto [totalNumbers,totalWavySc] = solve(0,-1,-1,true,true);
        return totalWavySc;
    }
    long long totalWaviness(long long num1, long long num2) {
        
        return func(num2)- func(num1-1);
    }
};