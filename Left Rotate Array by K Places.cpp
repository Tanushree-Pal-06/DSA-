class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        if (n<k) k=k%n;
        reverse(nums.begin(),nums.begin()+n);
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.begin()+n);
    }
};
