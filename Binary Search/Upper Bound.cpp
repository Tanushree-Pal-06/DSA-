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
};
