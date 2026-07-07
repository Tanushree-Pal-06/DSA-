class Solution {
public:
    int simpleRob(vector<int> &arr){
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<arr.size();i++){
            int pick=arr[i]+prev2;
            int notpick=0+prev;
            int curr= max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=nums.size()-1) temp1.push_back(nums[i]);
            if(i!=0) temp2.push_back(nums[i]);
        }
        return max(simpleRob(temp1),simpleRob(temp2));
    }
};
