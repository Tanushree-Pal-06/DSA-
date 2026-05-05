/*
Definition for Linked List
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
       
        int cnt=0;
        while( head!=NULL){
            head=head->next;
            cnt++;
        }
       
        return cnt;
    }
};
