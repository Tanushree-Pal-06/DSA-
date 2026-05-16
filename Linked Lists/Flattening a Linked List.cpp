/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* l1, Node* l2){
        Node* dummy=new Node(-1);
        Node* res=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->data<l2->data){
                res->bottom=l1;
                l1=l1->bottom;
                res=res->bottom;
            }
            else{
                res->bottom=l2;
                l2=l2->bottom;
                res=res->bottom;  
            }
        }
        if(l1!=NULL) res->bottom=l1;
        if(l2!=NULL) res->bottom=l2;
        if( dummy->bottom) dummy->bottom->next=NULL;
        return dummy->bottom;
    }
    Node* recur(Node* node){
        if(node==NULL || node->next==NULL) return node;
        Node* front=recur(node->next);
        return merge(node, front);
       
    }
    Node *flatten(Node *root) {
        // code here
    return recur(root);
        
    }
};
