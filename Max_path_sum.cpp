#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int fmax(TreeNode<int> *root,long long int &maxi){
    if(root==NULL){
        return 0;
    }
    long long int left=(fmax(root->left,maxi));
    long long int right=(fmax(root->right,maxi));
    long long int value=root->val;
    maxi=max(maxi,(left+right+value));
    return value+max(left,right);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
      if(root==NULL || root->left==NULL || root->right==NULL) return -1;
    long long int maxi=0;
    fmax(root,maxi);
    return maxi;
}