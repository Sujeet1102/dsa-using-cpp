#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data){
    Node* n = new Node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node* Insert(Node* root, int data){
    if (root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

void Preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void Postorder(Node* root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}


int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,25);
    Preorder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    Postorder(root);
}