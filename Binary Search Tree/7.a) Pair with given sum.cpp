#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

void pushElements(Node* root, stack<Node*> &s, bool direction){
    if(direction){
        while(root){
            s.push(root);
            root = root->left;
        }
        return;
    }
    while(root){
        s.push(root);
        root = root->right;
    }
}

int isPairPresent(struct Node *root, int target)
{
    if(!root) return 0;
    stack<Node*> s1, s2;
    int x, y;
    Node* temp;
    pushElements(root,s1, true);
    pushElements(root,s2,false);
    while(!s1.empty() && !s2.empty() && s1.top()->data < s2.top()->data){
        x = s1.top()->data;
        y = s2.top()->data;
        if(x+y == target) return 1;
        if(x+y<target){
            temp = s1.top();
            s1.pop();
            pushElements(temp->right,s1,true);
        }
        else{
            temp = s2.top();
            s2.pop();
            pushElements(temp->left,s2, false);
        }
    }
    return 0;
}