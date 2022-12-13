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
bool Search(Node* root, int data){
    if (root == NULL) return false;
    else if (data == root->data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,25);
    int num;
    cout << "Enter Number: ";
    cin >> num;
    if(Search(root, num)) cout << "Found";
    else cout << "Not Found";
}
