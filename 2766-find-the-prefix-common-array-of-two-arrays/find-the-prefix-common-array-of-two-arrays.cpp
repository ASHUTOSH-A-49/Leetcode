class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> a(51,0),b(51,0);
        vector<int> c;
        // c.push_back(0);
        // a.insert(A[0]);
        // b.insert(B[0]);
        for(int i = 0;i<n;i++){
            a[A[i]] = 1;
            b[B[i]] = 1;
            int cnt = 0;
            for(int i = 0;i<=n;i++){
                if(a[i]==1 && b[i]==1) cnt++;
            }
            c.push_back(cnt);
        }
        return c;
    }
};