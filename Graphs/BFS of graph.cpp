class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans;
        queue<int> q;
        vector<int> vis(adj.size());
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            
            for(auto it:adj[top]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return ans;
    }
};
