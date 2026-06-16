// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        string s=exp;
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(((s[i]>='A'&& s[i]<='Z')||
            (s[i]>='a' && s[i]<='z') ||
            (s[i]>='0' && s[i]<='9'))){
                st.push(string(1,s[i]));
            }
            else{
                char op=s[i];
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push("("+s2+op+s1+")");
                
            }
        }
        return st.top();
    }
};
