#include<iostream>
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
Node* findMin(Node* root){
    Node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

Node* Delete(Node* root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(data < root->data){
        root->left = Delete(root->left, data);
    }
    else if(data > root->data){
        root->right = Delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
void Inorder(Node* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,25);
    Inorder(root);
    cout << endl;
    root = Delete(root, 8);
    Inorder(root);
    cout << endl;
    root = Delete(root, 20);
    Inorder(root);
    cout << endl;
}