class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int floor=-1;
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            
            if(arr[mid]<=x){
                floor=max(floor,mid);
                l=mid+1;
            }
            else h=mid-1;
        }
        return floor;
    }
};
