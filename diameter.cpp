#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int findMax(TreeNode<int> *root,int&maxi){
    if(root==NULL){
        return 0;
    }
    int lh=findMax(root->left,maxi);
    int rh=findMax(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return max(lh,rh)+1;
} 
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi=0;
    findMax(root,maxi);
    return maxi;
	// Write Your Cod;e Here.
    
    
}
