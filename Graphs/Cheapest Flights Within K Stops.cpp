class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(n,1e9);
        queue<pair<int ,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k)continue;
            for(auto i : adj[node]){
                int next=i.first;
                int c=i.second;
                if(cost+c<dist[next] && stop<=k){
                    dist[next]=cost+c;
                    q.push({stop+1,{next,cost+c}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};
