  #include <bits/stdc++.h>
   template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


    void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    node->data=node->next->data;
    LinkedListNode<int> *temp=node->next;
    node->next = temp->next;
    delete temp;
}