/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void addLeft(Node* root,vector<int> & ans){
        if(root==NULL)return;
        if(root->left || root->right)ans.push_back(root->data);
        if(root->left)
           addLeft(root->left, ans);
        else
           addLeft(root->right, ans);
           //this ensures tht left boundary is considered properly
        //   ex:
        //        1
        //       /          in such cases we need to look at right nodes also
        //      2
        //       \
        //        4
    }
    
    void addRight(Node* root, vector<int> &ans){
        if(root==NULL)return;
        if(root->right ||root->left)ans.push_back(root->data);
        if(root->right)addRight(root->right,ans);
        else  addRight(root->left,ans); //same as for left boundary
    }
    
    void addLeaves(Node* root , vector<int> &ans){
        if(root == NULL)return;
    
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ;
        }
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL)return ans; 
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ans;
        }
        ans.push_back(root->data);
        vector<int> left;
        addLeft(root->left,left);
        vector<int> right;
        addRight(root->right,right);
        vector< int> leaves;
        addLeaves(root,leaves);
        
        for(int i=0;i<left.size();i++){
            ans.push_back(left[i]);
        }
        
        for(int i=0;i<leaves.size();i++){
            ans.push_back(leaves[i]);
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<right.size();i++){ // did size-1 to prevent including the root again 
            ans.push_back(right[i]);
        }
        return ans;
    }
};
