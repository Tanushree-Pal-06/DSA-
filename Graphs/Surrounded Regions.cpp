class Solution {
public:
    void bfs(int x, int y,int n,int m, vector<vector<char>>& board){
        queue<pair<int,int>> q;
        q.push({x,y});
        board[x][y]='#';
        while(!q.empty()){
            auto [a,b]=q.front();
            
            q.pop();
            if(a>0 && board[a-1][b]=='O'){
                q.push({a-1,b});
                board[a-1][b]='#';
            }
            if(a<n-1 && board[a+1][b]=='O'){
                q.push({a+1,b});
                board[a+1][b]='#';
            }
            if(b>0 && board[a][b-1]=='O'){
                q.push({a,b-1});
                board[a][b-1]='#';
            }
            if(b<m-1 && board[a][b+1]=='O'){
                q.push({a,b+1});
                board[a][b+1]='#';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<m;i++){
            //upper row
            if(board[0][i]=='O')bfs(0,i,n,m,board);
            //bottom row
            if(board[n-1][i]=='O')bfs(n-1,i,n,m,board);
        }
        for(int i=0;i<n;i++){
            //leftmost col
            if(board[i][0]=='O')bfs(i,0,n,m,board);
            //rightmost col
            if(board[i][m-1]=='O')bfs(i,m-1,n,m,board);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#')board[i][j]='O';
                else board[i][j]='X';
            }
        }
        
    }
};
