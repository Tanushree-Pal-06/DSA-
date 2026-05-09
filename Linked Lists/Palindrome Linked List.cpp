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
    bool isPalin(string &s){
        int l=0;
        int r=s.size()-1;
        while(l<=r){
           if(s[l]-'0'!=s[r]-'0') return false;
           else{
            l++;
            r--;
           }
        }
        return true;
      }
    bool isPalindrome(ListNode* head) {
        string s="";
        ListNode* temp=head;
        while(temp!=NULL){
            s+=temp->val;
            temp=temp->next;
        }
        return isPalin(s);
    }
};
