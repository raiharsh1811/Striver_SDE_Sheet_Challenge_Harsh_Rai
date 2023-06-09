#include <bits/stdc++.h>
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root) {
  if (!root)
    return NULL;

  stack<TreeNode<int> *> s;
  s.push(root);

  while (!s.empty()) {
    auto p = s.top();
    s.pop();

    if (p->right)
      s.push(p->right);
    if (p->left)
      s.push(p->left);

    if (!s.empty())
      p->right = s.top();

    p->left = NULL;
  }

  return root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root) {
  if (!root)
    return NULL;

  TreeNode<int> *curr = root;
  while (curr) {
    if (curr->left) {
      TreeNode<int> *node = curr->left;
      while (node->right)
        node = node->right;

      node->right = curr->right;
      curr->right = curr->left;
      curr->left = NULL;
    }

    curr = curr->right;
  }

  return root;
}