class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto it: adj[node]){
                int adjnode=it.first;
                int d=it.second;
                if(dis+d<dist[adjnode]){
                    dist[adjnode]=dis+d;
                    pq.push({dis+d,adjnode});
                }
            }
        }
        return dist;
    }
};
