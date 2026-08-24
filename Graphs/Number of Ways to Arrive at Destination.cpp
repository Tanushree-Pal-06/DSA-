class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //creating the adjacent list
        vector<vector<pair<int,int>>> adj(n);
        for(int it=0;it<roads.size();it++){
            adj[roads[it][0]].push_back({roads[it][1],roads[it][2]});
            adj[roads[it][1]].push_back({roads[it][0],roads[it][2]}); 
        }

        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        // {dist,node}
        int mod=(int)(1e9+7);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto [dis,node]=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int d=it.second;
                //first time visiting with shortest dist
                if(dis+d<dist[adjNode]){
                    dist[adjNode]=dis+d;
                    pq.push({dis+d,adjNode});
                    ways[adjNode]=ways[node];
                }
                //visiting gain on same min dist
                else if(dis+d==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
