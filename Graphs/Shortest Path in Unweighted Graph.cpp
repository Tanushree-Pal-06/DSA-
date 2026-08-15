class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(V,INT_MAX);
        queue <pair<int,int>> q;
        q.push({src,0});
        dist[src]=0;
        while(!q.empty()){
            auto[node,d]=q.front();
            if(node==dest)return d;
            q.pop();
            
            for(auto it: adj[node]){
                if(dist[it]> d+1){
                    dist[it]=d+1;
                    q.push({it,d+1});
                }
                
            }
        }
        if(dist[dest] == INT_MAX)
            return -1;
        
        return dist[dest];
    }
};
