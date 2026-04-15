class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
        int leftd = 1,rightd = 1;
        int li = (startIndex-1+n)%n;
        int ri = (startIndex+1)%n;
        bool check = false;
        if(words[startIndex]==target) return 0;
        while(li!=startIndex){
        string s = words[li];
            if(s==target){
            check = true;
             break;
             }
            else{
            li = (li-1+n)%n;
            leftd++;
            }
        }
        while(ri!=startIndex){
        string s = words[ri];
            if(s==target){
            check = true;
             break;
             }
            else{
            ri = (ri+1)%n;
            rightd++;
            }
        }
        if(!check) return -1;
        return min(leftd,rightd);
    }
};