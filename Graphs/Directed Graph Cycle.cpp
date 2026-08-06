class Solution {
  public:
    bool dfs(int i,vector<int> &vis,vector<int> &pathvis,vector<vector<int>> &adj){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj)==true)return true;
                
            }
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[i]=0;
        return false;
    } 
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj)==true)return true;
            }
        }
        return false;
    }
};
