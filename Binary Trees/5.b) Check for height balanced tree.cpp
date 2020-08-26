//Question Link
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};

int height(Node* root, bool &flag){
    if(!root) return 0;
    
    int l = height(root->left, flag);
    int r = height(root->right, flag);
    if(abs(l-r)>1) flag = false;
    return 1+max(l,r);
}

bool isBalanced(Node *root)
{
    bool flag = true;
    int h = height(root, flag);
    return flag;
}