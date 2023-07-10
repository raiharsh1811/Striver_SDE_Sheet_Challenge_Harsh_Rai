#include <bits/stdc++.h> 
class Node{
    public:
    TreeNode<int>* node;
    int X;
    int Y;
    Node(TreeNode<int>* _node , int _x,int _y){
        node = _node;
        X = _x;
        Y = _y;
    }
};
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // node,x,y;
    queue<Node> q;
    vector<int> ans;
    map<int,vector<int>> travesal;
    Node n(root,0,0);
    q.push(n);
    while(!q.empty()){
        Node curr = q.front();
        q.pop();
        TreeNode<int>* temp = curr.node;
        int x = curr.X;
        int y = curr.Y; 
        travesal[x].push_back(temp->data);
        if(temp->left != NULL){
            Node tempL = Node(temp->left,x-1,y+1);
            q.push(tempL);
        }
        if(temp->right != NULL){
            Node tempR = Node(temp->right,x+1,y+1);
            q.push(tempR);
        }
    }

    for(auto it : travesal){
        for(auto i : it.second){
            ans.push_back(i);
        }
    }

    return ans;
}