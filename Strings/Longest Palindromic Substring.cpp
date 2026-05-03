class Solution {
public:
    string expand(string& s, int l, int r){
      while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            // odd length
            string s1 = expand(s, i, i);

            // even length
            string s2 = expand(s, i, i+1);

            if(s1.size() > ans.size()) ans = s1;
            if(s2.size() > ans.size()) ans = s2;
        }

        return ans;
    }
};
