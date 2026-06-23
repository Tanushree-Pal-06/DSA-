class Solution {
public:
    vector<int> nge(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pgee(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i])st.pop();
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
     vector<int> psee(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i])st.pop();
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long  subArrMax(vector<int>& nums){
        long long total=0;
        vector<int> Nge=nge(nums);
        vector<int> Pgee=pgee(nums);
        for(int i=0;i<nums.size();i++){
            int left=i-Pgee[i];
            int right=Nge[i]-i;
            total+=(1LL*left*right*nums[i]);

        }
        return total;
    }
        long long  subArrMin(vector<int>& nums){
        long long total=0;
        vector<int> Nse=nse(nums);
        vector<int> Psee=psee(nums);
        for(int i=0;i<nums.size();i++){
            int left=i-Psee[i];
            int right=Nse[i]-i;
            total+=(1LL*left*right*nums[i]);

        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArrMax(nums)-subArrMin(nums);
    }
};
