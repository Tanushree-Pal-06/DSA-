class Solution {
public:
    bool backtrack(vector<vector<char>>&board,string word, int i, int j, int k){
        int n=board.size();
        int m=board[0].size();

        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0||i>=n ||j>=m|| board[i][j]!=word[k]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='/0';
        if(backtrack(board,word,i+1,j,k+1)||backtrack(board,word,i-1,j,k+1)||backtrack(board,word,i,j+1,k+1)||backtrack(board,word,i,j-1,k+1)){
            return true;
        }
        board[i][j]=temp;
        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(backtrack(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
