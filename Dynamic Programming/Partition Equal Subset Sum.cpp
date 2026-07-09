class Solution {
public:
 bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<bool> prev(sum+1,0) , curr(sum+1,0);
        prev[0]=curr[0]=true;
        if (arr[0] <= sum)   prev[arr[0]]=true;
        
        for(int i=1;i<arr.size();i++){
            for(int target=1;target<=sum;target++){
                bool nottake=prev[target];
                bool take=false;
                if(arr[i]<=target) take= prev[target-arr[i]];
                curr[target]=take | nottake;
            
            }
            prev=curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int halfsum=sum/2;
        return isSubsetSum(nums,halfsum);  // because if one exists other will definetely do 
    }
};
