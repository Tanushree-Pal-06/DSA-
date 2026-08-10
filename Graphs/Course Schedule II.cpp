class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);;
        }

        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
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
        // check if topo sort has same no of vertices
        if(ans.size()==numCourses)return ans;
        return {};
    }
};
