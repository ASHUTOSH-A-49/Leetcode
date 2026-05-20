class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        set<int> a,b;
        vector<int> c;
        // c.push_back(0);
        // a.insert(A[0]);
        // b.insert(B[0]);
        for(int i = 0;i<n;i++){
            a.insert(A[i]);
            b.insert(B[i]);
            int cnt = 0;
            for(int i: a){
                if(b.find(i)!=b.end()) cnt++;
            }
            c.push_back(cnt);
        }
        return c;
    }
};