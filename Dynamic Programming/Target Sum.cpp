class Solution {
public:
        int perfectSum(vector<int>& arr, int target) {
        // space optimized code
        
        vector<int> prev (target+1,0), curr(target+1,0);
        
        // for handling zeros in array
       if(arr[0]==0) prev[0]=2;
       else prev[0]=1;

       if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;
       // 
        for(int i=1;i<arr.size();i++){
            curr[0] = (arr[i]==0) ? prev[0]*2 : prev[0];
            for(int s=1;s<=target;s++){
                int notpick=prev[s];
                int pick=0;
                if(arr[i]<=s)pick=prev[s-arr[i]];
                curr[s]=pick+notpick;
            }
            prev=curr;
        }
        return prev[target];
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int totsum=0;
        for(int i=0;i<arr.size();i++){
            totsum+=arr[i];
        }
        
        if(totsum-diff<0 || (totsum-diff)%2 ) return 0;
        return perfectSum(arr,(totsum-diff)/2);
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};
