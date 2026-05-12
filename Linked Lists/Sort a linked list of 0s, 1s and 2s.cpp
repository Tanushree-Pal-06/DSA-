/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
     Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
        // Create a dummy node
        Node* dummyNode = new Node(-1);
        
        // Temp pointer to build merged list
        Node* temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Choose smaller node
            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
    }

    // Function to find middle of linked list
    Node* findMiddle(Node* head) {
        // If list empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Slow and fast pointers
        Node* slow = head;
        Node* fast = head->next;

        // Move fast twice as fast as slow
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return middle node
        return slow;
    }

    // Function to perform merge sort
    Node* segregate(Node* head) {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle node
        Node* middle = findMiddle(head);

        // Split into two halves
        Node* right = middle->next;
        middle->next = nullptr;
        Node* left = head;

        // Recursively sort both halves
        left = segregate(left);
        right = segregate(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedLists(left, right);
}
};
