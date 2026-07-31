class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<int>> &vis){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x>0 && grid[x-1][y]=='1'&& !vis[x-1][y]){
                q.push({x-1,y});
                vis[x-1][y]=1;
            }
            if(x<n-1 && grid[x+1][y]=='1'&& !vis[x+1][y]){
                q.push({x+1,y});
                vis[x+1][y]=1;
            }
            if(y>0 && grid[x][y-1]=='1'&& !vis[x][y-1]){
                q.push({x,y-1});
                vis[x][y-1]=1;
            }
            if(y<m-1 && grid[x][y+1]=='1'&& !vis[x][y+1]){
                q.push({x,y+1});
                vis[x][y+1]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,n,m,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
