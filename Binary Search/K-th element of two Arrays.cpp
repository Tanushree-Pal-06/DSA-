class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int l=0;
        int r=0;
        int cnt=0;
        bool flag1=false;
        bool flag2=false;
        while(cnt<k){
            if( l<a.size() && (r >= b.size() || a[l] < b[r])){
                l++;
                flag1=true;
                flag2=false;
            }
            else if ( r<b.size() || ( l>= a.size() ||(a[l]>b[r]))){
                r++;
                flag2=true;
                flag1=false;
            }
            cnt++;
        }
        if(flag1) return a[l-1];
        if(flag2) return b[r-1];
        return 0;
    }
};
