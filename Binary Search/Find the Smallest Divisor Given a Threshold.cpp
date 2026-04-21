class Solution {
public:
    
    int divsum(vector<int>& nums, int k){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= ceil(double(nums[i])/k);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int l=1;  
       int h=INT_MIN; // max
       
       for(int i=0;i<nums.size();i++){
        
           h=max(h,nums[i]);
        }

        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            if(divsum(nums,mid) <= threshold) {
                  ans=min(ans,mid);
                  h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
