class Solution {
public:
    bool checkValidString(string s) {
        int open_limit = 0;
        int close_limit = 0;
        int n = s.size();

        // Left to Right: 
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') open_limit++;
            else open_limit--;
            
            if (open_limit < 0) return false; // Too many ')'
        }

        // Right to Left:
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') close_limit++;
            else close_limit--;
            
            if (close_limit < 0) return false; // Too many '('
        }

        return true;
    }
};