class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1;
        int ans=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1 || ( cnt!=1 && nums[i]==nums[i+1] )){
              if (nums[i+1]==nums[i]+1 ) cnt++;
              }
            else cnt=1;
            ans=max(ans,cnt);  
        }
        return ans;
    }
};
