// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>>ans={};
        Node* tail=head;
        int h=0;
        int t=0;
        while(tail->next!=NULL){
            tail=tail->next;
            t++;
        }
        while(h<t){
            if(head->data+tail->data==target){
                
                ans.push_back({head->data, tail->data});
                head=head->next;
                h++;
                tail=tail->prev;
                t--;
            }
            else if(head->data+tail->data<target){
                head=head->next;
                h++;
            }
            else{
                tail=tail->prev;
                t--;
            }
        }
        return ans;
        
    }
};
