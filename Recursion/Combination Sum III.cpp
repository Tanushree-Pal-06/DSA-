class Solution {
public:
    void findCombo(int start, int n, int k, vector<int> &ds,vector<vector<int>> &ans){
        if(n==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(n<0 || ds.size()>k) return;
        for(int i=start;i<=9;i++){
            ds.push_back(i);
            findCombo(i+1,n-i,k,ds,ans);
            ds.pop_back();
        }
    }



    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        findCombo(1,n,k,ds,ans);
        return ans;
    }
};
