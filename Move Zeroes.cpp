class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=1;
        while(r<n){
            if(nums[l]==0){
                while(r<n && nums[r]==0  ){
                     r++;
                }
                if(r<n)swap(nums[l],nums[r]);
            }
            l++;
            r++;
        }
        
    }
};
