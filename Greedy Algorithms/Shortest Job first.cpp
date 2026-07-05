class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        
        sort(bt.begin(),bt.end());
        int totalwt=0;//for the first job waiting is 0
        int wttime=0;
        for(int i=0;i<bt.size()-1;i++){
            wttime+=bt[i];
            totalwt+=wttime;
        }
        
    
        
       return totalwt/bt.size();
        
    }
};
