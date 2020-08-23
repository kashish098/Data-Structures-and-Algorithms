// Question Link
//https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1 
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

class solver
{
private:

    map<Node*, Node*> m;
    set<Node*> s;
    queue<Node*> q;
    void nextLevel(){
        while(1){
            Node* temp = q.front();
            q.pop();
            if(!temp){
                if(q.size() != 0){
                    q.push(NULL);
                }
                return;
            }
            if(temp->left && s.find(temp->left) == s.end()){
                q.push(temp->left);
                s.insert(temp->left);
            }
            if(temp->right && s.find(temp->right) == s.end()){
                q.push(temp->right);
                s.insert(temp->right);
            }
            
            if(m[temp] && s.find(m[temp]) == s.end()){
                q.push(m[temp]);
                s.insert(m[temp]);
            }
        }
    }

void parent(Node* root, Node* p){
    if(!root) return;
    m[root] = p;
    parent(root->left, root);
    parent(root->right, root);
}

Node* findNode(Node* root, int val){
    if(!root) return NULL;
    if(root->data == val) return root;

    Node* l = findNode(root->left, val);
    if(l) return l;

    Node* r = findNode(root->right, val);
    if(r) return r;

    return NULL;
}

public:

    vector <int> KDistanceNodes(Node* root, int target , int k){
        vector<int> v;
        if(!root) return v;
    
        Node* temp = findNode(root, target);
        if(!temp) return v;
           
        int level = 0;
    
        parent(root, NULL);
    
        q.push(temp);
        s.insert(temp);
        q.push(NULL);
    
        while(!q.empty()){
            if(level == k){
                while(!q.empty()){
                    Node *temp = q.front();
                    q.pop();
                    if(temp) v.push_back(temp->data);
                }
                sort(v.begin(), v.end());
                return v;
            }
    
            level++;
            nextLevel();
        }
        return v;
    }
};