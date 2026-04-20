class Solution {
public:
    bool possible(vector<int>& arr,int day, int m , int k){
        int cnt=0;
        int nB=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day) cnt++;
            else{
                nB+=cnt/k;
                cnt=0;
            }
        }
        nB+=cnt/k;
     return (nB>=m); 
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
     if(1LL *m*k>bloomDay.size())return -1;
     int mini=INT_MAX;
     int maxi=INT_MIN;
     for(int i=0;i<bloomDay.size();i++){
        mini=min(mini,bloomDay[i]);
        maxi=max(maxi,bloomDay[i]);
     }
     int l=mini;
     int h=maxi;
     int ans=INT_MAX;
     while(l<=h){
        int mid=(l+h)/2;
        if(possible(bloomDay,mid,m,k)){
            ans=min(ans,mid);
            h=mid-1;
        }
        else{
            l=mid+1;
        }
     }
     return ans;
    }
};
