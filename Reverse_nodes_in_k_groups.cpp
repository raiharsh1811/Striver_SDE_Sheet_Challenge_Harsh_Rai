#include <bits/stdc++.h>



        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

int lengthOfLinkedList(Node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
Node* reversal(Node* head, int n, int b[], int i){

    // Skip b[i] = 0

    while(b[i]==0 && i<n){

        i++;

    }

 

    if(!head || !head->next || i == n)

        return head;

 

    int counter = b[i];

    Node* prev=NULL, *curr=head, *ahead;

 

    while(curr!=NULL && counter--){

        ahead = curr->next;

        curr->next = prev;

        prev = curr;

        curr = ahead;

    }

 

    head->next = reversal(curr, n, b, i+1);

    return prev;

}

 

Node *getListAfterReverseOperation(Node *head, int n, int b[]){

    if(!head)

        return NULL;

    return reversal(head, n, b, 0);

}