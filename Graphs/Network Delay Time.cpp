class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> time(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        time[k]=0;
        int ans=0;
        while(!pq.empty()){
            auto [tim,node]=pq.top();
            
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int t=it.second;

                if(tim+t<time[adjnode]){
                    time[adjnode]=t+tim;
                    pq.push({t+tim,adjnode});
                }
            }
        }
        for(int i=1;i<time.size();i++){
            if(time[i]==1e9) return -1;
            ans=max(ans,time[i]);
        }
        
        return ans;
    }
};
