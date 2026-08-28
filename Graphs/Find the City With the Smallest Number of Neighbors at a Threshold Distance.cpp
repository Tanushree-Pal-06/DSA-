class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // create adj matrix
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto it:edges){
            //bidirectional edges
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        //node to itself takes 0
        for(int i=0;i<n;i++)dist[i][i]=0;
        
        //perform floyd warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e9&& dist[k][j]!=1e9){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        //find city
        int city=-1;
        int cntmax=n+1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntmax){
                cntmax=cnt;
                city=i;
            }
        }

        return city;
    }
};
