class Solution {
public:
    int maxDepth(string s) {
        if(s.size()==1) return 0;
        int cnt=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')') {
                maxi=max(maxi,cnt);
                cnt--;
            }
            else continue;
        }
        return maxi;
    }
};
