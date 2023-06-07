#include <bits/stdc++.h>



 
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };



Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* temp=new Node<int>(0);
    Node<int>* res=temp;
    if(first==NULL) return second;
    if(second==NULL) return first;
    while(first!=NULL && second!=NULL){
        if(first->data>second->data){
            temp->next=second;
            temp=temp->next;
            second=second->next;
        }
        else{
            temp->next=first;
            temp=temp->next;
            first=first->next;
        }
    }
    if(first) temp->next=first;
    else temp->next=second;
    return res->next;
}
