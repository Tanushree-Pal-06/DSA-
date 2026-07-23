class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V]; // 0 indexed , if 1 indexed do [V+1]
        for(int i=0;i<edges.size();i++){
            //since its undirected
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(V);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                
                vector<int> comp;
                
                queue<int> q;
                q.push(i);
                vis[i]=1;
                
                while(!q.empty()){
                    int top=q.front();
                    comp.push_back(top);
                    q.pop();
                    for(auto it : adj[top]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
                ans.push_back(comp);
                
            }
        }
        return ans;
    }
};
