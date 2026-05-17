class Solution {
public:
    double recur(double x, long long n){
        if(n == 0) return 1;
        return x * recur(x, n - 1);
    }

    double myPow(double x, int n) {
        long long N = n;
        bool neg = N < 0;

        if(neg) N = -N;

        double ans = recur(x, N);

        return neg ? 1/ans : ans;
    }
};
