#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode< int > *> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode< int > *node = q.front();
        q.pop();
        if(node == NULL){
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            node->next = q.front();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return;
}