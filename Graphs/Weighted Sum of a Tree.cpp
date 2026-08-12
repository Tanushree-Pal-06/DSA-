class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<vector<int>> adj(parent.size());
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> depth(nums.size());
        depth[0]=1;
        int height=1;

        queue<int> q;
        q.push(0);
        //height and depth calc
        while(!q.empty()){
            int el=q.front();
            q.pop();
            
            for(auto it:adj[el]){
                depth[it]=depth[el]+1;
                height=max(height,depth[it]);
                q.push(it);
            }
        }
        long long ans =0;
        for(int i=0;i<nums.size();i++){
        long long wt=(1LL* nums[i] *(height -depth[i]+1));
           ans+=wt; 
        }
        return ans;
    }
};
