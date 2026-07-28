class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                
                auto top=q.front();
                q.pop();
                int x=top.first.first;
                int y=top.first.second;
                
                int step= top.second;
                
                ans[x][y]=step;
                if(x>0 && !vis[x-1][y]){
                    q.push({{x-1,y},step+1});
                    vis[x-1][y]=1;
                }
                if(x<n-1 && !vis[x+1][y]){
                    q.push({{x+1,y},step+1});
                    vis[x+1][y]=1;
                }
                if(y>0 && !vis[x][y-1]){
                    q.push({{x,y-1},step+1});
                    vis[x][y-1]=1;
                }
                if(y<m-1 && !vis[x][y+1]){
                    q.push({{x,y+1},step+1});
                    vis[x][y+1]=1;
                    
                }

            }
        }
        return ans;
    }
};
