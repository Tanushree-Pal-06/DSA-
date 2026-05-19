class Solution {
public:
    void recur(int n ,string curr, vector<string> &result,int cnt, int left){
        if(curr.length()==2*n){
            result.push_back(curr);
            return ;
        }
        if(left<n)recur(n,curr+"(",result,cnt+1,left+1);
        if(cnt>0) recur(n,curr+")",result,cnt-1,left);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur(n,"",ans,0,0);
        return ans;
    }
};
