class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int m=l+1;
        int h=nums.size()-1;
       
        vector<vector<int>> ans;
        for(int l=0;l<nums.size()-2;l++){
            if(l>0 && nums[l]==nums[l-1])continue;
            m=l+1;
            h=nums.size()-1;

        while(m<h){
            if(nums[l]+nums[m]+nums[h]==0){
                vector<int >temp={nums[l],nums[m],nums[h]};
                ans.push_back(temp);
                m++;
                h--;
                while( m<h && nums[m-1]==nums[m]) m++;
                while(m<h && nums[h]==nums[h+1]) h--;
            
            }
            else if(nums[l]+nums[m]+nums[h]<0) m++;
            else if(nums[l]+nums[m]+nums[h]>0) h--;
        }
        }
        return ans;
    }
};
