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
  
    void func(Node* node,vector<vector<int>> &ans,vector<int> &list){
        if(node==NULL)return;
        if(node->left==NULL&& node->right==NULL){
            list.push_back(node->data);
            ans.push_back(list);
            list.pop_back();
            return;
        }
        list.push_back(node->data);
        func(node->left,ans,list);
        func(node->right,ans,list);
        list.pop_back();
        
    }  
    vector<vector<int>> Paths(Node* root) {
        // code here
        
        vector<vector<int>> ans;
        
        vector<int> list;
        func(root,ans,list);
        return ans;
    }
};
