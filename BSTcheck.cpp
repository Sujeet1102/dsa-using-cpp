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

// int RMin(Node* root){
//     Node* current = root;
//     if(current->left == NULL){
//         return current->data;
//     }
//     return RMin(current->left);
// }
// int RMax(Node* root){
//     Node* current = root;
//     if(current->right == NULL){
//         return current->data;
//     }
//     return RMax(current->right);
//}

bool IsBSTutil(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data < min && root->data > max && IsBSTutil(root->left, min, root->data) && IsBSTutil(root->right, root->data, max)){
        return true;
    }
    else{
        return false;
    }
}
bool IsBST(Node* root){
    return IsBSTutil(root, INT16_MIN, INT16_MAX);
}

int main(){
    Node* root = NULL;
    root = Insert(root,7);
    root = Insert(root,4);
    root = Insert(root,9);
    root = Insert(root,1);
    root = Insert(root,6);
    // root = Insert(root,5);
    // root = Insert(root,25);
    // int min = findMin(root);
    // int max = findMax(root);
    // cout << min<< endl << max << endl;
    // int Rmin = RMin(root);
    // int Rmax = RMax(root);
    // cout << Rmin<< endl << Rmax; 
    cout << IsBST(root);
}