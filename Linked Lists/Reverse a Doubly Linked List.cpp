/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr=head;
        Node* last=NULL;
        while(curr!=NULL){
            curr->prev=curr->next;
            curr->next=last;
            last=curr;
            curr=curr->prev; // moving forward
            
        }
        
        return last;
    }
};
