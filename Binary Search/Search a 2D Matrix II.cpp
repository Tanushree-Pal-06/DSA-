class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {   int n=matrix.size();
    int m=matrix[0].size();
    int i=0;
    int l=0;
    int h=m-1;
    while(i<n-1){
        int mid=(l+h)/2;
        if(matrix[i][mid]==target)return true;
        else if(matrix[i][mid]<target){
            if(i<n-1)i++;
            else break;
        }
        else if(matrix[i][mid]>target){
            h=mid-1;
        }
    }
     return false;   
    }
};
