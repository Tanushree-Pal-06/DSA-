class Solution {
public:
    long long  tothrs(vector<int>& nums , int k){
        long long thrs=0;
        for(int i=0;i<nums.size();i++){
            thrs+=ceil(double(nums[i])/k);
        }
        return thrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int l=1;
        int r=maxi;
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(tothrs(piles,mid)<=h){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
