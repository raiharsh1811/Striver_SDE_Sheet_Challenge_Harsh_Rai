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
    
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
     LinkedListNode<int>*dummy=head;
     while(head!=NULL){
        LinkedListNode<int> *temp=head->next;
        head->next=dummy;
        dummy=head;
        head=temp;
    }
    return dummy;
}