class Solution {
public:
    int myAtoi(string s) {
       int ans=0;
       bool neg=false;
       bool signUsed=false;
       bool flag=false; //to check if there has been any existin g number consu=idered before '-' it can be a zero as
       for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            if(!flag && !signUsed) continue;//leading spaces
            else break;
        }
        else if(!signUsed&& !flag && s[i]=='-'){
            neg=true;
            signUsed=true;
        }
        else if(!signUsed &&  !flag && s[i]=='+'){
             signUsed=true;
            continue;

        }
        else if(isdigit(s[i])){
                int digit = s[i] - '0';

                // check overflow BEFORE updating ans
                if(ans > (INT_MAX - digit) / 10){
                    return neg ? INT_MIN : INT_MAX;
//This ensures:ans * 10 + digit will not exceed INT_MAX
                }

                ans=ans*10+digit;
                flag=true;
        }
        
        else break;
       }
        if(neg) ans=-ans;
        return ans;
    }
};
