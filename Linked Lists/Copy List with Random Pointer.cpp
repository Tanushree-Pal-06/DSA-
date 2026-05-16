/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void copyNodes(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
    }
    void connectRandom(Node*head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copy=temp->next;
            if(temp->random) copy->random=temp->random->next;
            else copy->random=NULL;
            temp=temp->next->next;
        }
    }
    Node* connectNext(Node* head){
        Node* dummy=new Node(-1);
        Node* res=dummy;
        Node* temp=head;
        while(temp!=NULL){
            Node* copy=temp->next;
            res->next=copy;
            temp->next=copy->next;
            res=copy;
            temp=temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        copyNodes(head);
        connectRandom(head);
        return connectNext(head);
        
    }
};
