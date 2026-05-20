class Solution {
  public:
  
    bool func(int ind, int sum, vector<int> &arr){
        if(sum==0) return true;
        if(sum<0 || ind==arr.size())return false;
        return func(ind+1,sum-arr[ind],arr) || func(ind+1,sum,arr);
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        return func(0,k,arr);
        
    }
};
