class Solution {
  public:
     int priority(char op){
        if(op=='^')return 3;
        else if(op=='*' || op=='/')return 2;
        else if(op=='+' || op=='-')return 1;
        return -1;
    }
    string infixToPrefix(string &s) {
        // code here
         string ans="";
        stack<char> st;
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]>='A'&& s[i]<='Z') ||
            (s[i]>='a'&& s[i]<='z') ||
            (s[i]>='0'&& s[i]<='9') 
            ) {ans+=s[i];}
            
            else if(s[i]==')')st.push(s[i]);
            
            else if(s[i]=='('){
                while(!st.empty() && st.top()!=')'){
                 
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() &&
      (priority(s[i]) < priority(st.top()) ||
      (priority(s[i]) == priority(st.top()) && s[i] == '^'))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
