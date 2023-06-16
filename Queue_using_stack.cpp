#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> s;
    int size;
    public:
    Queue() {
        // Initialize your data structure here.
        size = 0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s.push(val);
        size++;
        return;
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(isEmpty()){
            return -1;
        }
        if(size==1){
            int element = s.top();
            s.pop();
            size--;
            return element;
        }
        stack<int> temp;
        int sz = size;
        while(sz!=1){
            temp.push(s.top());
            s.pop();
            sz--;
        }
        int element = s.top();
        s.pop();
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        size--;
        return element;
    }

    int peek() {
        // Implement the peek() function here.
        if(isEmpty()){
            return -1;
        }
    
        stack<int> temp;
        int sz = size;
        while(sz!=1){
            temp.push(s.top());
            s.pop();
            sz--;
        }
        int element = s.top();
        
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
       
        return element;
        
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (size==0);
    }
};