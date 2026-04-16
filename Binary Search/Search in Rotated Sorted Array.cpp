class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target)return mid;
            else if(nums[l]<=nums[mid]){//left is sorted
               if(nums[l]<=target && target<nums[mid])
               { // target lies in left half
                h=mid-1;
               }
               else{// target lies in right half
                l=mid+1;
               }
            }

            else{ //right is sorted
     
                if (nums[mid] < target && target <= nums[h]) {       // If target lies in the sorted right half, search there
                    l= mid + 1;
                }
                // Else search in the left half
                else {
                    h = mid - 1;
                }
            }

        }
        return -1;
    }
};
