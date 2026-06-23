class Solution {
public:
    vector<int> nse(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
            if(st.empty()) nse[i]=n; // if no ele's smaller
            else nse[i]=st.top();
            st.push(i);
    }
    return nse;
    }

 vector<int> psee(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()])st.pop();
            if(st.empty()) psee[i]=-1; // if no ele's smaller
            else psee[i]=st.top();
            st.push(i);
    }
    return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int mod=(int)(1e9+7);
        long long  total=0;
        vector<int> Nse=nse(arr);
        vector<int> Psee=psee(arr);
        for(int i=0;i<arr.size();i++){
            int left=i-Psee[i];
            int right=Nse[i]-i;
            total=(total+(1LL*left*right*arr[i])%mod)%mod;
        }
        return total;
    }
};
