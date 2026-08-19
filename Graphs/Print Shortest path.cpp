class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Code here
        
        //adjacent list creation
        vector<vector<pair<int,int>>> adj(V+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        //dijkastra algo implementation
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V+1,1e9);
        vector<int> parent(V+1); // for memorizing the parent
        for(int i=0;i<=V;i++){
            parent[i]=i;
        }
        
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int d=it.second;
                if(dis+d<dist[adjNode]){
                    dist[adjNode]=dis+d;
                    pq.push({dis+d,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        
        if(dist[dest]==1e9)return {-1};
        vector<int> path;
        int node=dest;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);
        
        reverse(path.begin(),path.end());
        return path;
        
    }
};
