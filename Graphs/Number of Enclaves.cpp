class Solution {
public:
     void bfs(int x, int y,int n,int m, vector<vector<int>>& board){
        queue<pair<int,int>> q;
        q.push({x,y});
        board[x][y]=2;
        while(!q.empty()){
            auto [a,b]=q.front();
            
            q.pop();
            if(a>0 && board[a-1][b]==1){
                q.push({a-1,b});
                board[a-1][b]=2;
            }
            if(a<n-1 && board[a+1][b]==1){
                q.push({a+1,b});
                board[a+1][b]=2;
            }
            if(b>0 && board[a][b-1]==1){
                q.push({a,b-1});
                board[a][b-1]=2;
            }
            if(b<m-1 && board[a][b+1]==1){
                q.push({a,b+1});
                board[a][b+1]=2;
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        for(int i=0;i<m;i++){
            //upper row
            if(grid[0][i]==1)bfs(0,i,n,m,grid);
            //bottom row
            if(grid[n-1][i]==1)bfs(n-1,i,n,m,grid);
        }
        for(int i=0;i<n;i++){
            //leftmost col
            if(grid[i][0]==1)bfs(i,0,n,m,grid);
            //rightmost col
            if(grid[i][m-1]==1)bfs(i,m-1,n,m,grid);
        }
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
                
            }
        }
    return cnt;
    }
};
