class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

  public:
    Node* head=NULL;
    int cnt=0;
    myQueue() {
        // Initialize your data members
    }

    bool isEmpty() {
        // check if the queue is empty
        return cnt==0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode=new Node(x);
        if(cnt==0){
            head=newNode;
            head->next=NULL;
            
        }
       else
        {Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
       
        temp->next=newNode;
        newNode->next=NULL;}
        cnt++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(cnt==0)return;
        Node * temp=head;
        head=head->next;
        delete temp;
        cnt--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(cnt==0)return -1;
        return head->data;
        
    }

    int size() {
        // Returns the current size of the queue.
        return cnt;
    }
};
