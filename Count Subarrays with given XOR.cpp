class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        long cnt=0;
        map<int,int> mpp;
        mpp[0]=1;
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^arr[i];
            int x=xr^k;
            
            cnt+=mpp[x];
        
            mpp[xr]++;
        }
        return cnt;
    }
};
