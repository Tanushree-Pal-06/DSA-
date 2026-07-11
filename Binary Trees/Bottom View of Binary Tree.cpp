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
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL)return ans;
        queue<pair<Node*,int>>q;
        map<int,int> mpp;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            Node* node=p.first;
            int line=p.second;
            q.pop();
         
            mpp[line]=node->data;
            //this stores last node of every level
            if(node->left)q.push({node->left,line-1});
            if(node->right)q.push({node->right,line+1});
        }
        
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
