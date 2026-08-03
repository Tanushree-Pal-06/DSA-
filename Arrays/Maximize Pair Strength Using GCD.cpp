class Solution {
public:

    long long gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    long long maxPairStrength(vector<int>& nums) {
        long long maxi=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long g=gcd(nums[i],nums[j]);
                long long strength=(1LL*nums[i]*nums[j])/(g*g);
                maxi=max(strength,maxi);
            }
        }
        return maxi;
    }
};
