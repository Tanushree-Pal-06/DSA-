class Solution {
public:
    bool possible(vector<int> &arr, int cap,int days){
        int sum=0;
        int d=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=cap) sum+=arr[i];
            else{
                d+=1;
                sum=arr[i];
            }
        }
        if(sum>0)d+=1;
        if(d<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int ans=-1;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }

        int l=*max_element(weights.begin(), weights.end());
        int h=sum;
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(weights,mid,days)){
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
