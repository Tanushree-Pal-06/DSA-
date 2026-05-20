class Solution {
  public:
  
    void recur(int i,int n,string curr, vector<string> & ans,string s){
        if(i==n){
            if(!curr.empty())ans.push_back(curr);
            return;
        }
        recur(i+1,n,curr+s[i],ans,s);
        recur(i+1,n,curr,ans,s);
    }   
  
    vector<string> AllPossibleStrings(string s) {
        // Code here
        int n=s.size();
        vector<string> ans;
        recur(0,n,"",ans,s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
