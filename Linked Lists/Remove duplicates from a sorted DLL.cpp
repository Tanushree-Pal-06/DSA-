/*
class Node {
public:
    int data;  // value stored in node
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
}
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(head==NULL or head->next==NULL) return head;
        Node* pre=head;
        Node* ahead=head->next;
        while(ahead!=NULL){
            if(pre->data!=ahead->data){
                ahead=ahead->next;
                pre=pre->next;
            }
            else{
                while(ahead != NULL && pre->data==ahead->data){
                    ahead=ahead->next;
                }
                pre->next=ahead;
                if(ahead!=NULL) ahead->prev=pre;
            }
        }
        return head;
    }
};
