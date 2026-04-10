class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        int n_sum=0;
        int repeating;
        bool flag=false;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            sum+=arr[i];
            n_sum+=i+1;
            if( !flag && arr[i]==arr[i-1]&& sum!=n_sum ){
                repeating=arr[i];
                sum=sum-arr[i];
                flag=true;
            }
        }
        int missing=n_sum-sum;
        return {repeating,missing};
    }
};
