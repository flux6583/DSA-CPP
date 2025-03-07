// Problem Statement

// Predecessor and Successor in BST - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/_893049

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* temp = root;
    
    int pred = -1;
    int succ = -1;
    
    while(temp->data != key)
    {
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }
    
    // pred and succ
    
    // pred
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}
