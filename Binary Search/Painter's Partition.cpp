class Solution {
  public:
      bool possible(vector<int> &arr,int k, int num){
        int cnt=0;
        int sum=arr[0];
        for(int i=1;i<arr.size();i++){
            if(sum+arr[i]<=num)sum+=arr[i];
            else{
                cnt++;
                sum=arr[i];
            }
        }
        if(sum>0) cnt++;
        if(cnt<=k)return true;
        return false;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        if(arr.size()<k)return -1;
        int ans;
        int l=INT_MIN; // l should be maximum element
        int h=0; // h should be sum of the array
        for(int i=0;i<arr.size();i++){
            l=max(l,arr[i]);
            h+=arr[i];
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(arr,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};
