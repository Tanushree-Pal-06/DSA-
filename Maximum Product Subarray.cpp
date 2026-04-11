class Solution {
public:
    int maxProduct(vector<int>& nums) {
       if(nums.size()==1)return nums[0];
       int sum=0;
       int csum=1;
       for(int i=0;i<nums.size();i++){

         csum=csum*nums[i];
        
        sum=max(sum,csum);
        if(csum<=0)csum=1;
       }
       return sum;
    }
};
