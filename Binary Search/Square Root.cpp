class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l=1;
        int h=n;
        int root=INT_MIN;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid*mid==n) return mid;
            else if(mid*mid>n) h=mid-1;
            else{
                root=max(mid,root);
                l=mid+1;
            } 
        }
        return root;
    }
};
