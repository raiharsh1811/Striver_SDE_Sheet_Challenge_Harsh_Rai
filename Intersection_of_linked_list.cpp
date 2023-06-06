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

        int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* d1=firstHead;
    Node* d2=secondHead;
    int cunt=0;
    while(d1!=NULL){
        d1=d1->next;
        cunt++;
    }
    d1=firstHead;
    for(int i=0;i<cunt;i++){
        d2=secondHead;
        while(d1!=NULL && d2!=NULL){
            if(d1->data==d2->data){
                return d2->data;
            }
            d2=d2->next;
        }
        d1=d1->next;
    }
    return NULL;
}
//    unordered_set<node*> st;
//     while(head1 != NULL) {
//        st.insert(head1);
//        head1 = head1->next;
//     }
//     while(head2 != NULL) {
//         if(st.find(head2) != st.end()) return head2;
//         head2 = head2->next;
//     }
//     return NULL;