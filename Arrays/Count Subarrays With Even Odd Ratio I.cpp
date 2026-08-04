class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count=0;
        double ratio=(double)a/b;
        for(int i=0;i<nums.size();i++){
            int x=0;//even
            int y=0;//odd
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0)x++;
                else y++;
                if(y!=0 && ((double)x/y)<=ratio)count++;
            }
        }
        return count;
    }
};
