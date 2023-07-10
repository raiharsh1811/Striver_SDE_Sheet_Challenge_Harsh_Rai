#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void find(BinaryTreeNode<int> *root,vector<int>&ans){
    if(root->left!=NULL)find(root->left,ans);
    ans.push_back(root->data);
    if(root->right!=NULL)find(root->right,ans);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int>ans;
    if (root != NULL) {
      find(root, ans);
    }
    int l=0,r=ans.size()-1;
    while(l<r){
        if(ans[l]+ans[r]==k){
            return true;
        }
        else if(ans[l]+ans[r]>k){
            r--;
        }
        else{
            l++;
        }
    }
    return false;
}