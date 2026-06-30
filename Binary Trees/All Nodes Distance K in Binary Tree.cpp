/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_track,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent_track[node->left]=node;
                q.push(node->left);
            }
             if(node->right){
                parent_track[node->right]=node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map <TreeNode*,TreeNode*> parentTrack;
        markParents(root,parentTrack,target);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*>que;
        que.push(target);
        visited[target]=true;
        int dist=0;
        while(!que.empty()){
            int size=que.size();
            if(dist++==k) break;
            for(int i=0;i<size;i++){
                TreeNode * node=que.front();
                que.pop();
                if(node->left && !visited[node->left]){
                    que.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    que.push(node->right);
                    visited[node->right]=true;
                }
                if(parentTrack[node] && !visited[parentTrack[node]]){
                    que.push(parentTrack[node]);
                    visited[parentTrack[node]]=true;
                }
            }
        }

        while(!que.empty()){
            TreeNode* cur=que.front();
            que.pop();
            ans.push_back(cur->val);
        }
return ans;
    }
};
