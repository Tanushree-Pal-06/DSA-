class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string ans="";
        int l=0;
        int r=0;
        while(l<strs[0].size() && 
        r<strs[n-1].size() && strs[0][l]==strs[n-1][r]){
            ans+=strs[0][l];
            l++;
            r++;
        }
        return ans;
    }
};
