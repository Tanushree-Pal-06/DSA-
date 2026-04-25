// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int> arr){
        int l=0;
        int h=arr.size()-1;
        int ans=arr.size(); // we intialize ans with n becos if the row contains 0 ones , it will go like m-m that is 0
        while (l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==1){
               ans=mid;
               h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int ind= -1; 
        int ans=0;
        for(int i=0;i<n;i++){
            if(m-lowerBound(arr[i])>ans){
                ans=m-lowerBound(arr[i]);
                ind=i;
            }
            if(m-lowerBound(arr[i])==ans && i<ind){
                ind=i;
            }
        }
        return ind;
        
    }
};
