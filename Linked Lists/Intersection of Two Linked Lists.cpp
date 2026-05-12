/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1=0;
        int cnt2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
            temp1=temp1->next;  
            cnt1++;
        }
        while(temp2!=NULL){
            temp2=temp2->next;  
            cnt2++;
        }
        temp1=headA;
        temp2=headB;
        if(cnt1>cnt2){
            int diff=cnt1-cnt2;
            for(int i=0;i<diff;i++){
                temp1=temp1->next;
            }
        }
        else if(cnt1<cnt2){
            int diff=cnt2-cnt1;
            for(int i=0;i<diff;i++){
                temp2=temp2->next;
            }
        }
        while(temp1 && temp2){
            if(temp1==temp2)return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
       return NULL;
    }
};
