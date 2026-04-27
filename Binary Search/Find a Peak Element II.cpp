class Solution {
public:
    int maxele(vector<vector<int>>& mat,int n, int m ,int col){
        int maxval=-1;
        int maxind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxval){
                maxval=mat[i][col];
                maxind=i;
            }
        }
        return maxind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=(l+h)/2;
            int maxrow= maxele(mat,n,m,mid);
            int left=(mid>0)?mat[maxrow][mid-1]:-1;
            int right=(mid<m-1)?mat[maxrow][mid+1]:-1;
            if(mat[maxrow][mid]>left && mat[maxrow][mid]>right){
                return {maxrow,mid};
            }
            else if(mat[maxrow][mid]<left){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};
