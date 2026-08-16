class Solution {
  public:
    void topoSort(int i,vector<vector<pair<int,int>>> &adj,stack<int> &st, vector<int> &vis){
        vis[i]=1;
        for(auto it:adj[i]){
            int v=it.first;
            if(!vis[v])topoSort(v,adj,st,vis);
        }
        st.push(i);
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        // build the adjacency list u->{v,wt},{v2,wt2}..
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        //perform the topo sort
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i,adj,st,vis);
            }
        }
        //relax the edge weights
        vector<int> dist(V,1e9);
        dist[0]=0;
        while(!st.empty()){
            int v=st.top();
            st.pop();
            if(dist[v] != 1e9){
            for(auto it: adj[v]){
                int node=it.first;
                int d=it.second;
                if(dist[v]+d<dist[node]){
                    dist[node]=dist[v]+d;
                    
                }
            }
                
            }
        }
        //mark unreachable nodes as -1
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9)dist[i]=-1;
        }
        return dist;
    }
};
