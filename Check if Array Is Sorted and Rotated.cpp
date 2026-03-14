class Solution {
public:
    bool check(vector<int>& nums) {
        int wrong=1;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if(nums[(i+1)%n]<nums[i]){
                    wrong--;
                 }
        }
        if(wrong<0){
            return false;;
        }
        return true;
    }
};
