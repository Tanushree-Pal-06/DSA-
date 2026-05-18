class Solution {
  public:
    void insert(stack<int> &st,int n){
        if(st.empty() || st.top()<=n){
            st.push(n);
        }
        else{
            int val=st.top();
            st.pop();
            insert(st,n);
            st.push(val);
        }
    }
    void sortStack(stack<int> &st) {
        // code here
        if(!st.empty()){
            int temp=st.top();
            st.pop();
            sortStack(st);
            insert(st,temp);
        }
    }
};
