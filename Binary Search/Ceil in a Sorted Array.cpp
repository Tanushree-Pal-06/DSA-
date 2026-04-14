// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int ceil=n;
        int l=0;
        int h=n-1;
        while(l<=h){
            int  mid=(l+h)/2;
            if(arr[mid]>=x){
                ceil=min(ceil,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ceil==n) ceil=-1;
        return ceil;
    }
};
