class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n)return -1;
        if(s==0)return 0;
        int num=0;
        int remsum=s;
        
        for (int i=0;i<n;i++){
            int digit=min(remsum,9);
            num=num*10+digit;
            remsum-=digit;
        }
        return num;
    }
};
