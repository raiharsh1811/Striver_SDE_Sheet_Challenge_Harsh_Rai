#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
   
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    bool ok=true;
      vector<int>res;
    if(root==NULL){
        return res;
    }
  
    while(!q.empty()){
        //BinaryTreeNode<int> *temp=q.front();
        int x=q.size();
        vector<int>ans(x);
        for(int i=0;i<x;i++){
            BinaryTreeNode<int> *temp=q.front();
            q.pop();
                int index=ok?i:x-i-1;
                ans[index]=temp->data;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        ok=!ok;
        for(auto it:ans){
            res.push_back(it);
        }
    }
    return res;
    
}

