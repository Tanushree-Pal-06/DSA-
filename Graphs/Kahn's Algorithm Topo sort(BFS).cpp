class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> indegree(V);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        
        queue<int> q;
        
        for(int  i=0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return ans;
    }
};
