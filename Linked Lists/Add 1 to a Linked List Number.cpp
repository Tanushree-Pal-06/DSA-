/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int helper(Node* temp){
        if(temp==NULL) return 1;
        int carry=helper(temp->next);
        temp->data=temp->data+carry;
        if(temp->data<10){
            return 0;
        }
        temp->data=0;
        return 1;
        
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry=helper(head);
        if(carry==1){
            Node* newnode=new Node(1);
            newnode->next=head;
            head=newnode;
        }
        return head;
        // return head of list after adding one
    }
};
