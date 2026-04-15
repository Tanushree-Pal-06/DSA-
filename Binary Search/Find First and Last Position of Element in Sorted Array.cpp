class Solution {
public:
    int first(vector<int>& nums, int target){
        int n=nums.size();
        int l=0;
        int h=n-1;
        int first=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
               first=mid;
               h=mid-1;
            }
            else if(nums[mid]<target) l=mid+1;
            else h=mid-1;
        }
        return first;
    }
    int last(vector<int>& nums, int target){
        int n=nums.size();
        int l=0;
        int h=n-1;
        int last=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
               last=mid;
               l=mid+1;
            }
            else if(nums[mid]<target) l=mid+1;
            else h=mid-1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int f=first(nums,target);
        if(f==-1)return {-1,-1};
        int l=last(nums,target);
        return {f,l};
    }
};
