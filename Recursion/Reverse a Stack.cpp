class Solution {
  public:
  
    void insertAtBottom(stack<int> &st,int k){
        if(st.empty()){
            st.push(k);
            return ;
        }
        
        int topval=st.top();
        st.pop();
        insertAtBottom(st,k);
        st.push(topval);
        
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int topval=st.top();
        st.pop();
        
        reverseStack(st);
        insertAtBottom(st,topval);
    }
};
