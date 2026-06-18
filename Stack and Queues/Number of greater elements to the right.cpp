
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n=arr.size();
        int ind=indices.size();
        vector<int> cnt(ind);
        for(int i=0;i<ind;i++){
            for(int j=indices[i]+1;j<n;j++){
                if(arr[j]>arr[indices[i]]) cnt[i]++;
            }
        }
        return cnt;
        
    }
};
