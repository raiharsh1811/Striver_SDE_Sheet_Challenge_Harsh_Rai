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
   TreeNode<int>* func(TreeNode<int> *root, int &k)
        {
            if (root == NULL)
                return NULL;

            TreeNode<int> *right = func(root->left, k);
            if (right != NULL)
                return right;
            k--;

            if (k == 0)
                return root;

            return func(root->right, k);
        }

    int kthSmallest(TreeNode<int> *root, int &k)
    {
        TreeNode<int>*ans=func(root,k);
        return ans->data;
       	//         vector<int> ans;
       	//         inorderTraversal(root,ans);

       	//         if(ans.size() < k)
       	//         {
       	//             return -1;
       	//         }

       	//         return ans[k-1];
    }
