class Solution {
  public:
    string preToPost(string &s) {
        // code here
        stack<string> st;
        for(int i=s.size()-1;i>=0;i--){
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
                st.push(s1+s2+op);
            }
        }
        return st.top();
    }
};
