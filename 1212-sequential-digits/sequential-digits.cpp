class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int l = 0,r = 1;
        vector<int> ans;
        while(r<9){
            string sub = s.substr(l,r-l+1);
            int num = stoi(sub);
            if (num >= low && num <= high) { 
                ans.push_back(num); 
            }
            if (r < 8) { 
                l++; 
                r++; 
            }else { 
                int next_length = (r - l + 1) + 1; 
                l = 0; 
                r = next_length - 1; 
            }
        }
        return ans;

    }
};