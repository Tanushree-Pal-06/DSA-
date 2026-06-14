// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        string s=pre_exp;
        stack<string> st;
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]>='A' && s[i]<='Z')||
            (s[i]>='a' && s[i]<='z')){
                st.push(string(1, s[i])); // char → string;
            }
            
            else{
                char op=s[i];
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();
                st.push("("+top1+op+top2+")");
            }
        }
        return st.top();
    }
};
