class Solution {
  public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mini=INT_MAX;
        int pos;
        while(l<=h){
            int mid=(l+h)/2;
            // both the parts are sorted
            if(mini>nums[mid]){
            mini=nums[mid];
            pos=mid;
            }
          if(nums[l]<=nums[mid] && nums[mid]<=nums[h] ){
               if(nums[l]<mini){
                mini=nums[l];
                pos=l;
               }
               break; 
            }
            // left is sorted
           else if(nums[l]<=nums[mid]){
            l=mid+1;
           }
           //right is sorted
           else if(nums[mid]<=nums[h]){
            h=mid-1;
           }
        }
        return pos;
    }
    
    int findKRotation(vector<int> &arr) {
       return findMin(arr);
    }
};
