
class Solution {
  public:
    int cntstudent(vector<int> &arr,int pages){
        int student=1;
        long long pgstu=0;
        for(int i=0;i<arr.size();i++){
            if(pgstu+arr[i]<=pages){
                pgstu+=arr[i];
            }
            else{
                student++;
                pgstu=arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(cntstudent(arr,mid)>k)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
