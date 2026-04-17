class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;  
            if(nums[mid]==target)return true;

          // Edge case: all three are equal, we cannot determine which side is sorted
        if (nums[l] == nums[mid] && nums[mid] == nums[h]) {
            l++;
            h--;
            continue;
        }

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
     
        if (nums[mid] < target && target <= nums[h]) {  
                    l= mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }

        }
        return false;
    
    }
};
