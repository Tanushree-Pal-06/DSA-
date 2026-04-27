class Solution {
  public:
     int upperBound(vector<int>& arr, int target) {
        // code here
        if(arr[arr.size()-1]<=target) return arr.size();
        int up=arr.size();
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>target){
                up=min(up,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return up;
    }
    int blackbox(vector<vector<int>> &mat,int n ,int m ,int x){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upperBound(mat[i],x);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i=0;i<n;i++){
            l=min(l,mat[i][0]);
            h=max(h,mat[i][m-1]);
        }
        int req=(n*m)/2;
        
        while(l<=h){
            int mid=(l+h)/2;
            int smallerEq=blackbox(mat,n,m,mid);
            if(smallerEq<=req) l=mid+1;
            else h=mid-1;
        }
        return l;
        
    }
};
