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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mapMail;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            //mail starts from 1st index not 0
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapMail.find(mail)==mapMail.end()){
                    mapMail[mail]=i;
                }
                else{
                    ds.unionBySize(i,mapMail[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it:mapMail){
            string mail=it.first;
            int node=ds.findUpar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
