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

int findMin(Node* root){
    Node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

int findMax(Node* root){
    Node* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}
int RMin(Node* root){
    Node* current = root;
    if(current->left == NULL){
        return current->data;
    }
    return RMin(current->left);
}
int RMax(Node* root){
    Node* current = root;
    if(current->right == NULL){
        return current->data;
    }
    return RMax(current->right);
}

int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,25);
    int min = findMin(root);
    int max = findMax(root);
    cout << min<< endl << max << endl;
    int Rmin = RMin(root);
    int Rmax = RMax(root);
    cout << Rmin<< endl << Rmax;
}