/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL)return head;
        int len=0;
        
        ListNode* tail=NULL;
        ListNode* temp=head;
        while(temp){
            len++;
            
            if(temp->next==NULL){
                tail=temp;
            }
            temp=temp->next;
        }
        if(k%len==0) return head;
        k=k%len;
        
        ListNode* t=head;
        for(int i=1;i<len-k;i++){
              t=t->next;
        }
        ListNode* newHead=t->next;
        t->next=NULL;
        tail->next=head;
        return newHead;
    }
};
