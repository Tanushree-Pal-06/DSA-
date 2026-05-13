/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if (!head_ref || !(*head_ref)) return;

        Node* temp = *head_ref;

        while (temp) {
            if (temp->data == x) {
                // If node is head
                if (temp == *head_ref) {
                    *head_ref = temp->next;
                    if (*head_ref) (*head_ref)->prev = NULL;
                }
                // Middle or last node
                else {
                    if (temp->prev) temp->prev->next = temp->next;
                    if (temp->next) temp->next->prev = temp->prev;
                }
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
    }
};
