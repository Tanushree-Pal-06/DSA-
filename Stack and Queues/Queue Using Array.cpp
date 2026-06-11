class myQueue {

  public:
    vector<int> arr;
    int size;
    int front=-1;
    int rear=-1;
    int cnt=0;
    myQueue(int n) {
        // Define Data Structures
        arr.resize(n);
        size=n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==-1;
    }

   bool isFull() {
    return cnt == size;
}

   void enqueue(int x) {
    if(cnt == size) return;

    if(front == -1)
        front = 0;

    arr[++rear] = x;
    cnt++;
}

    void dequeue() {
    if(cnt == 0) return;

    front++;
    cnt--;

    if(cnt == 0) {
        front = rear = -1;
    }
}

    int getFront() {
        // Returns the front element of the queue.
        if(front==-1)return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(rear==-1)return -1;
        return arr[rear];
    }
};
