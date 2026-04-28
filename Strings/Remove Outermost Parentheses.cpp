class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(balance>0){
                    result+=s[i];
                }
                balance++;
            }
            else{
                balance--;
                if(balance>0){
                    result+=s[i];
                }
               
            }
        }
        return result;
    }
};
