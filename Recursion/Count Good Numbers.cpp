class Solution {
public:

const int MOD = 1e9 + 7;
    int recur(long long n,int ans){
        if(n==0)return 1;
        if(n%2==0){
        ans=5*recur(n-1,ans);
        }
        else{
        ans=4*recur(n-1,ans);
        }
        return ans;

    }
    int countGoodNumbers(long long n) {
        int ans=1;
        int res=recur(n,ans);

        return res% MOD;
    }
};
