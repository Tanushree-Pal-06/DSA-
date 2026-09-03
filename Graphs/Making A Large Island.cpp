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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        //step 1:make all connected components
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                for(int i=0;i<4;i++){
                    int adjr=row+dr[i];
                    int adjc=col+dc[i];
                    if(adjr>=0 && adjr<n && adjc>=0 && adjc<n && grid[adjr][adjc]==1){
                        int nodeNo=row*n+col;
                        int adjNo=adjr*n+adjc;
                        ds.unionBySize(nodeNo,adjNo);
                    }
                }
            }
        }
    // step 2:try converting all 0 to 1 and find max island size
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                set<int> comp;
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    if(newr>=0 && newc>=0 && newr<n && newc<n && grid[newr][newc]==1){
                        int newNo=newr*n+newc;
                        comp.insert(ds.findUpar(newNo));

                    }
                }

                int size=0;
                for(auto it:comp){
                    size+=ds.size[it];
                }
                mx=max(mx,size+1);
            }
        }


        //for safety , in case all nodes are 1, we just take comp with greastest size
        // for all nodes find size of their ultimate parent
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUpar(i)]);
        }

        return mx;
    }
};
