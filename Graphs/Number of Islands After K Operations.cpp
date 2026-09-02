class DisjointSet{

    public:
        vector<int>parent,size;    
        DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
          }
        }

        int findUpar(int node){
            if(node==parent[node])return node;
            return parent[node]=findUpar(parent[node]);
        }

        void unionBySize(int u,int v){
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            if(ulp_u==ulp_v)return ;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }

};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis (n,vector<int>(m,0));
        int cnt=0;
        vector<int> ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            cnt++;
            vis[row][col]=1;
            //4 directions
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjr=row+dr[i];
                int adjc=col+dc[i];
                if(adjr>=0 && adjc>=0 && adjr<n && adjc<m){
                    if(vis[adjr][adjc]==1){
                        //derived
                        int nodeNo=row*m+col;
                        int adjNo=adjr*m+adjc;
                        
                        if(ds.findUpar(nodeNo)!=ds.findUpar(adjNo)){
                            cnt--;
                            ds.unionBySize(nodeNo,adjNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
