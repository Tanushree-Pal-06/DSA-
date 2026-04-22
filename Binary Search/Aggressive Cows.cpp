class Solution {
  public:
    bool canWePlace(vector<int> &arr,int dist,int cows){
       
        int cnt=1;
        int last=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=dist){
                cnt++;
                last=arr[i];
            }
        }
        if(cnt>=cows) return true;
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int ans;
        int l=1;
        int h=stalls[stalls.size()-1]-stalls[0];
        while(l<=h){
            int mid=(l+h)/2;
            if(canWePlace(stalls,mid,k)) {
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
        
    }
};
