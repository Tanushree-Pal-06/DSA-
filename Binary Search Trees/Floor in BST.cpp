/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        if(root==NULL)return -1;
        int ans=-1;
        while(root!=NULL){
            if(root->data==k)return root->data;
            else if(root->data<k){
                ans=max(ans,root->data);
                root=root->right;
                
            }
            else{
                root=root->left;
            }
            
        }
        return ans;
    }
};
