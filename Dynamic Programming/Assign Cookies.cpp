class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=g.size()-1;
        int r=s.size()-1;
        int ans=0;
        while(l>=0 && r>=0){
            if(s[r]>=g[l]){
              ans++;
              l--;
              r--;
            }
            else{
                l--;
            }
        }
        return ans;
    }
};
