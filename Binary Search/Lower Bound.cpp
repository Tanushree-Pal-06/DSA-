class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        if(target>arr[n-1]) {
            return n;
            }
        
        int lb=n;
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>=target) {
                lb=min(lb,mid);
                r=mid-1;
            }
            else l=mid+1;
           
        }
        return lb;
    }
};
