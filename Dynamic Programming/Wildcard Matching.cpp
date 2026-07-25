class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m+1, false), curr(m+1, false);

        // Base case: empty string & empty pattern
        prev[0] = true;

        // Base case: empty string vs pattern with only '*'
        for (int j = 1; j <= m; j++) {
            bool allStar = true;
            for (int k = 1; k <= j; k++) {
                if (p[k-1] != '*') { allStar = false; break; }
            }
            prev[j] = allStar;
        }

        for (int i = 1; i <= n; i++) {
            // Empty pattern vs non-empty string → false
            curr[0] = false;

            for (int j = 1; j <= m; j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    curr[j] = prev[j-1];
                }
                else if (p[j-1] == '*') {
                    curr[j] = prev[j] || curr[j-1];
                }
                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
