class Solution {
public:
        int cnt=0;
        void merge(vector <int>& arr,int low, int mid, int high ){
        vector <int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if (arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while (right<=high){
            temp.push_back(arr[right]);
            right++;
            
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
  

    void countPairs(vector<int> &arr, int l, int mid, int r){
        int right=mid+1;
        for(int i=l;i<=mid;i++){
            while(right<=r &&  (long long) arr[i]> 2LL* arr[right]) right++;
            cnt+=(right-(mid+1));
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if ( l>=r) return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        countPairs(arr,l,mid,r);
        merge(arr,l,mid,r);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};
