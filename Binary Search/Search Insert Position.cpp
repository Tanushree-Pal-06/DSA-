class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
               if(nums[nums.size()-1]<target) return nums.size();
        int up=nums.size();
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
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
