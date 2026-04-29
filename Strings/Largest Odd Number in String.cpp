class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        string ans="";
        while(i>=0){
            char last=num[i];
            if((last-'0')%2==0){
                i--;
            }
            else{
                ans=num.substr(0,i+1);
                break;
            }
        }
       return ans;
    }
};
