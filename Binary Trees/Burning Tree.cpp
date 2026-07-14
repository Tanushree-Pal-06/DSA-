/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void parent(Node* root, unordered_map<Node*,Node*> &mpp){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mpp[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                mpp[node->right]=node;
            }
        }
    }
    
    Node* targetNode(Node* root,int target){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();
            if(target==curr->data)return curr;
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        return NULL;
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>parents;
        parent(root,parents);
        unordered_map<Node*,bool> vis;
        queue<Node*> q;
        Node* tar=targetNode(root,target);
        q.push(tar);
        vis[tar]=true;
        int sec=0;
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                if(parents[node] && !vis[parents[node]]){
                q.push(parents[node]);
                vis[parents[node]]=true;
                }
                if(node->left &&!vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right &&!vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                
            }
            if(!q.empty())sec++;
        }
        
        return sec;
        
        
    }
};
