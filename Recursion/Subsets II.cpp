class Solution {
public:
  void recur(int ind , vector<int>& nums,vector<int>&curr, vector<vector<int>>& ans){
        if(ind==nums.size()){ 
            ans.push_back(curr);
            return;}
        curr.push_back(nums[ind]);
        recur(ind+1,nums,curr,ans);
        
        curr.pop_back();
        recur(ind+1,nums,curr,ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>> ans;
        recur(0,nums,curr,ans);
        return ans;
    }
};
