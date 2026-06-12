/*
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
class myStack {

  public:
    Node* head;
    int cnt=0;
    myStack() {
        // Initialize your data members
        head = NULL;
    }

    bool isEmpty() {
        // check if the stack is empty
        return cnt==0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* node = new Node(x);
        node->next = head;
        head = node;
        cnt++;
    }

    void pop() {
        // Removes the top element of the stack
          if(head == NULL) return;

        Node* temp = head;
        head = head->next;
        delete temp;
        cnt--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(head == NULL) return -1;
        return head->data;
    }

    int size() {
        // Returns the current size of the stack.
        return cnt;
    }
};
