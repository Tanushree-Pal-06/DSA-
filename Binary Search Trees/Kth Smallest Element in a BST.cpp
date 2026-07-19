/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag=false;
    void inCnt(TreeNode* root,int &cnt,int k,int &ans){
        if(root==NULL|| flag)return;
        
        
        inCnt(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k){
           ans=root->val;
           flag=true;
           return;
        }
        inCnt(root->right,cnt,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans=0;
        inCnt(root,cnt,k,ans);
        return ans;
    }
};
