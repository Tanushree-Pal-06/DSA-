class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) { 
    int n=s.size();
    int m=g.size();
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int l=0;
    int r=0;
    while(l<m && r<n){
        if(s[r]>=g[l]){
          
            l++;
        }
         r++;

    } 
       return l; 
    }
};
