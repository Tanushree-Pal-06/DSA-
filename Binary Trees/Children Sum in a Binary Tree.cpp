/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    
    bool isSumProperty(Node *root) {
        // code here
        if(root->left==NULL && root->right==NULL)return true;
        int left=(root->left==NULL)?0:root->left->data;
        int right=(root->right==NULL)?0:root->right->data;
        if(root->data==(left+right)){
            if(root->left) return isSumProperty(root->left);
            if(root->right)return isSumProperty(root->right);
        }
        else {
            return false;
        }
        
    }
};
