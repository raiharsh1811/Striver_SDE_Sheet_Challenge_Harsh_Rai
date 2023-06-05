
 #include <bits/stdc++.h>


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node *findMiddle(Node *head) {
    // Write your code here
    int count=0;
    Node* dummy=head;
    while(dummy!=NULL){
        dummy=dummy->next;
        count++;
    }
        int c=1;
        Node* temp=head;
        while(c!=(count/2 )+1){
            temp=temp->next;
            c++;
        }
        return temp;
}

