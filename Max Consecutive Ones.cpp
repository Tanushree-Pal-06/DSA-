class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0;
        int maxsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                sum++;
            }
            
            else{
                maxsum=max(maxsum,sum);
                sum=0;
            }
            
        }
        maxsum=max(maxsum,sum);
        return maxsum;
    }
};
