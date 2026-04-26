class Solution {
public:
    bool search(vector<int> & arr,int target){
        int l=0;
        int h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            if(search(matrix[i],target)) return true;
        }
        return false;
    }
};
