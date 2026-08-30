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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            //cnt extra edge
            if(ds.findUpar(u)==ds.findUpar(v))cntExtra++;
            //make conn comp.
            else ds.unionBySize(u,v);

        }
        int cc=0;//conn comp.
        for(int i=0;i<n;i++){
                if(ds.parent[i]==i) cc++;
        }
        if(cntExtra>=cc-1)return cc-1;
        return -1;
    }
};
