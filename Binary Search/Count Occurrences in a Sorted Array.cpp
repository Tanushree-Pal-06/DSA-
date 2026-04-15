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
    int countFreq(vector<int>& arr, int target) {
        // code here
        int f=first(arr,target);
        if( f==-1) return 0;
        int l=last(arr,target);
        return l-f+1;
    }
};
