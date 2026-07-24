class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int>& ans ){
        vis[node]=1;
        ans.push_back(node);
        //traverse the neighbours
        for(auto it:adj[node]){
           if(!vis[it])dfs(it,adj,vis,ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<int> vis(adj.size());
        dfs(0,adj,vis,ans);
        return ans;
    }
};
